#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

enum State
{
	VALID,
	INVALID
};

enum State state = INVALID;

int my_atoi(char* a)
{
	assert(a);
	int flag = 1;
	int ret = 0;
	while (isspace(*a)) a++;
	if (*a == 0) return 0;
	else if (*a == '+')
	{
		flag = 1;
		a++;
	}
	else if (*a == '-')
	{
		flag = -1;
		a++;
	}

	while (isdigit(*a))
	{
		ret = ret * 10 + *a - '0';
		a++;
	}

	if (*a == 0)
	{
		state = VALID;
		return flag * ret;
	}
	else
	{
		return flag * ret;
	}
	
}

int main()
{
	char* a = "-1234";
	printf("%d", my_atoi(a));
	return 0;
}