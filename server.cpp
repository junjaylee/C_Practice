#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winSock2.h>
#include <WS2tcpip.h>
#include <IPHlpApi.h>
#include <cstdio>

#pragma comment (lib, "Ws2_32.lib")
#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main(int argc, char const *argv[])
{
	int iResult, iSendResult;
	WSADATA wsaData;
	struct addrinfo *result = NULL, *ptr = NULL, hints;
	char temp[DEFAULT_BUFLEN];

	printf("input the file you want to transfer\n");
	scanf("%s",temp);

	FILE *fp = fopen(temp, "rb");
	if (fp==NULL)
	{
		printf("open file %s failed\n",fp );
		return -1;
	}

	if (WSAStartup(MAKEWORD(2,2), &wsaData))
	{
		printf("server WSAStartup failed:%d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0)
	{
		printf("server getaddrinfo failed:%d\n", iResult);
		WSACleanup();
		return 1;
	}

	SOCKET listenSocket = INVALID_SOCKET;
	listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (listenSocket == INVALID_SOCKET)
	{
		printf("server failed at socket():%ld\n",WSAGetLastError());
		freeaddrinfo(result);
		return 1;
	}

	iResult = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		printf("server bind failed:%ld\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);

	if (listenSocket, SOMAXCONN)
	{
		printf("server listen socket failed %ld\n", WSAGetLastError());
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

    sockaddr_in client_addr;
    int nlen;
    SOCKET ClientSocket = INVALID_SOCKET;
    ClientSocket = accept(listenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET)
    {
    	printf("server accept failed:%ld\n", WSAGetLastError());
    	closesocket(listenSocket);
    	WSACleanup();
    	return 1;
    }

    closesocket(listenSocket);

    int num = 0;
    while(!feof(fp))
    {
    	num = fread(temp, 1, DEFAULT_BUFLEN, fp);
    	send(ClientSocket, temp, num, 0);
    }
    printf("server faile transfer success\n");

    fclose(fp);

    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR)
    {
    	printf("server shutdown failed:%ld\n", WSAGetLastError());
    	closesocket(ClientSocket);
    	WSACleanup();
    	return 1;
    }
    closesocket(ClientSocket);
    WSACleanup();
	return 0;
}
























