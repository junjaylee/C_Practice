#include <stdio.h>

int main(int argc, char const *argv[])
{
	typedef char * pStr;
	char string[4] = "abc";
	const char *p1 = string;
	const pStr p2 = string;  //like const int i; i is a const variable, so p2 is a const variable
	p1++;
	//p1[1] = 'e'; //const variable
	//p2++;  //const pointer
	p2[2] = 'e';
    printf("%s %s\n", p1, p2);
	return 0;
}

