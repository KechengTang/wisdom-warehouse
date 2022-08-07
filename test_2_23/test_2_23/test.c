#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

int my_strlen(const char* s)
{
	assert(s != NULL);
	int num = 0;
	while (*s != '\0')
	{
		s++;
		num++;
	}
	return num;
}

char* my_strcpy(char* dst, const char* src)
{
	char* cp = dst;
	while (*cp++ = *src++);
	return dst;
}
int main()
{
	char s[10] = "abcdefg";
	char ss[10] = { 0 };
	printf("%d\n", my_strlen(s));
	printf("%s", my_strcpy(ss, s));
}