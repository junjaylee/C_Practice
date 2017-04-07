/*client.cpp*/
//prevent winsock.h (version 1.1)from being included by whidows.h
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <cstdio>

#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "mswsock.lib")
#pragma comment(lib, "advApi32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512	

int main(int argc, char const *argv[])
{
	int iResult;
	WSADATA wsaData;
	struct addrinfo *result = NULL, *ptr = NULL, hints;
	char sendbuf[] = "this is a best for client";
	char recvbuf[DEFAULT_BUFLEN];
	char temp[DEFAULT_BUFLEN], file_name[DEFAULT_BUFLEN];
	printf("input ip address of server and file name\n");
	scanf("%s%s",temp, file_name);
	FILE *fp = fopen(file_name, "wb");
	if (fp == NULL)
	{
		printf("create file %s failed\n", file_name);
		return -1;
	}

	if(WSAStartup(MAKEWORD(2,2), &wsaData))
	{
        printf("client WSAStartup failed:%d\n", iResult);
        return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(temp, DEFAULT_PORT, &hints, &result);
	if (iResult != 0)
	{
		printf("client get addrinfo failed:%d\n", iResult);
		WSACleanup();
		return 1;
	}

	SOCKET ConnectSocket = INVALID_SOCKET;
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
	{
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET)
		{
			printf("client socket failed with error %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR)
		{
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}
	freeaddrinfo(result);
	if (ConnectSocket == INVALID_SOCKET)
	{
		printf("client unable to connect to server\n");
		WSACleanup();
		return 1;
	}

	int num=0;
	while(1)
	{
		num = recv(ConnectSocket, temp, DEFAULT_BUFLEN, 0);
		if (num == 0)
			break;
		
	    fwrite(temp, 1, num, fp);
		
	}
	printf("transmissiob done\n");
	fclose(fp);
	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}