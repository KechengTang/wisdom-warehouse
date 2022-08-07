#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//1.计数器的方法
size_t my_strlen1(const char* str)  //用const保护指针所指内容使其更安全
{
	int count = 0;
	assert(str != NULL); //确保str不为空指针
	while (*str != '\0')  //没到\0就加一
	{
		count++;
		str++;
	}
	return count;
}

//2.递归的方法
size_t my_strlen2(const char* str)
{
	assert(str != NULL);
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen2(str+1);
}

//3.指针-指针的方法
size_t my_strlen3(char* str)
{
	assert(str != NULL);
	char* p = str;
	while (*p != '\0')
		p++;
	return p - str;
}

char* my_strcpy(char* dest, const char* src)
{
	assert(src && dest);  //同时assert了src和dest都不是NULL
	char* ret = dest;
	while (*dest++ = *src++)  //将src赋值过去，不是\0就继续，这样可以一口气把\0也拷贝过去，妙！
	{
		;
		
	}
	return ret;
}

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	//找目标空间中的\0
	while (*dest)
	{
		dest++;
	}
	//拷贝
	while(*dest++ = *src++)
	{
		;
	}
	return ret;
}

int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	while(*arr1 == *arr2)
	{
		if (*arr1 == '\0')
		{
			return 0;
		}
		arr1++;
		arr2++;
	}
	if (*arr1 > *arr2)
		return 1;
	else
		return -1;
}

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* s1 = str1;
	char* s2 = str2;

	char* cur = str1;
	while (*cur)
	{
		s1 = cur;
		s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL; //找不到
}

void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;
	while (count)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
		count--;
	}
	return ret;
}

void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		//前->后
		while (count--)
		{
			*(char*)dest = *(char*)(src);
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//后->前
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[5] = { 0 };
	//此时strcpy()是不行的
	my_memmove(arr1+2, arr1, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}