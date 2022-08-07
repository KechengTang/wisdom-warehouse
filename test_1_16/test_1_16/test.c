#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = 9;
	int mid = 0;
	int key = 0;
	scanf("%d", &key);
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (key == arr[mid])
		{
			printf("找到了，下标为%d", mid);
			break;
		}
		if (key < arr[mid])
		{
			right = mid - 1;
		}
		if (key > arr[mid])
		{
			left = left + 1;
		}
	}
	if (left > right) printf("找不到！\n");
	return 0;
}