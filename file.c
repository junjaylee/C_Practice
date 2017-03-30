#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *stream;
	long offset;
	fpos_t pos;
	stream = fopen("/etc/passwd","r");
	fseek(stream, 5, SEEK_SET);
	printf("offset = %d\n", ftell(stream));
	rewind(stream);
	return 0;
}