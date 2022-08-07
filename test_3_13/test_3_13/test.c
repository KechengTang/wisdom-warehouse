#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

struct stu
{
	char name[20];
	int age;
	double score;
};

void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

int cmp(const void* a, const void* b)
{
	return strcmp(((struct stu*)a)->name , ((struct stu*)b)->name);
}

void bubble_sort(void* base, int num, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width )>0)
			{
				swap((char*)base+j*width, (char*)base+(j+1)*width,width);
			}
		}
	}
}

int main()
{
	struct stu arr[3] = { {"xuesheng1", 20, 55.5},{"nihao", 30, 88.0},{"woshishei", 10, 90.0} };
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp);
	printf("%s %s %s\n", arr[0].name, arr[1].name, arr[2].name);
	return 0;
}