#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int find(int* arr, int x, int y, int num)
{
	int a = 0;
	int b = y;
	while (a < x && b >= 0)
	{
		if (num > *(arr + a * x + b)) a++;
		else if (num < *(arr + a * x + b)) b--;
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { {1,3,5},{3,5,7},{5,7,9} };
	int num = 0;
	scanf("%d", &num);
	if (find(arr, 3, 3, num)) printf("´æÔÚ\n");
	else printf("²»´æÔÚ\n");
	return 0;
}