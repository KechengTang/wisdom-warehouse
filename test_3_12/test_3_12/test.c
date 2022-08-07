#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int findRound(const char* s, const char* ss)
{
	char tmp[300] = { 0 };
	strcpy(tmp, s);
	strcat(tmp, s);
	return strstr(tmp, ss)!=NULL;
}

int main()
{
	char s[] = "abcdef";
	char ss[] = "bcdefa";
	printf("%d", findRound(s, ss));
	return 0;
}