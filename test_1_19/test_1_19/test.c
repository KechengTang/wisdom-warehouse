#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void reverse_string(char* string)
{
	int len = strlen(string);
	char tmp = *string;
	*string = *(string + len - 1);
	*(string + len - 1) = '\0';
	if (strlen(string + 1) >= 2) reverse_string(string + 1);
	*(string + len - 1) = tmp;
}
int main()
{
	char s[] = "abcdef";
	reverse_string(s);
	printf("%s", s);
	return 0;
}