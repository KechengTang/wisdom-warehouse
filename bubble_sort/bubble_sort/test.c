#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void bubble_sort(int arr[], int arrsize)
{
	int i = 0;
	for (i = 0; i < arrsize - 1; i++)
	{
		int j = 0;
		int flag = 0;
		for (j = 0; j < arrsize - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag == 0) break;
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, len);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}