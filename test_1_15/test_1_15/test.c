#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	for (i = 101; i <= 200; i+=2)
	{
		int j = 0;
		for (j = 3; j <=sqrt(i); j += 2)
		{
			if (i % j == 0) break;
		}
		if (j > sqrt(i) ) printf("%d ", i);
	}
	return 0;
}
