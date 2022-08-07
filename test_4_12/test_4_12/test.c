#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//char* my_strncat(char* a, char* b, int n)
//{
//	int i = 0, j = 0;
//	while (a[i] != 0) i++;
//	for (j = 0; j < n; j++)
//	{
//		a[i + j] = b[j];
//	}
//	a[i + j] = 0;
//	return a;
//}
//
//char* my_strncpy(char* a, char* b, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		*(a + i) = *(b + i);
//	}
//	*(a + i) = 0;
//	return a;
//}
//
//int main()
//{
//	char a1[20] = "abc";
//	char* a2 = "12345";
//	my_strncpy(a1, a2, 5);
//	printf(a1);
//	return 0;
//}

//亦或的妙用
void find(int arr[], int n, int* p1, int* p2)
{
	int i = 0;
	int sum = 0;
	//计算两个single num亦或的结果
	for (i = 0; i < n; i++)
	{
		sum ^= arr[i];
	}

	//找到single word不同的一位
	int pos = 0; 
	for (i = 0; i < 32; i++)
	{
		if (sum & (1 << i))
		{
			pos = i;
			break;
		}
	}

	//分两组分别亦或
	*p1 = *p2 = 0;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] & 1 << pos)
		{
			*p1 ^= arr[i];
		}
		else
		{
			*p2 ^= arr[i];
		}
	}
}

int main()
{
	int arr[10] = { 1,2,3,3,4,4,5,5,6,6 };
	int num1 = 0;
	int num2 = 0;
	int* p1 = &num1;
	int* p2 = &num2;
	find(arr, 10, p1, p2);
	printf("%d %d", *p1, *p2);
	return 0;
}