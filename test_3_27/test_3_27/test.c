#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//1.�������ķ���
size_t my_strlen1(const char* str)  //��const����ָ����ָ����ʹ�����ȫ
{
	int count = 0;
	assert(str != NULL); //ȷ��str��Ϊ��ָ��
	while (*str != '\0')  //û��\0�ͼ�һ
	{
		count++;
		str++;
	}
	return count;
}

//2.�ݹ�ķ���
size_t my_strlen2(const char* str)
{
	assert(str != NULL);
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen2(str+1);
}

//3.ָ��-ָ��ķ���
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
	assert(src && dest);  //ͬʱassert��src��dest������NULL
	char* ret = dest;
	while (*dest++ = *src++)  //��src��ֵ��ȥ������\0�ͼ�������������һ������\0Ҳ������ȥ���
	{
		;
		
	}
	return ret;
}

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	//��Ŀ��ռ��е�\0
	while (*dest)
	{
		dest++;
	}
	//����
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
	return NULL; //�Ҳ���
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
		//ǰ->��
		while (count--)
		{
			*(char*)dest = *(char*)(src);
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//��->ǰ
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
	//��ʱstrcpy()�ǲ��е�
	my_memmove(arr1+2, arr1, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}