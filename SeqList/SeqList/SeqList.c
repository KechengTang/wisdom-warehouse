#include "SeqList.h"

void SeqListPrint(SeqList* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps != NULL);
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->capacity = ps->size = 0;
	}
}

void SeqListCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
			return;
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPopFront(SeqList* ps)
{
	SeqListErase(ps, 0);
}

void SeqListPopBack(SeqList* ps)
{
	SeqListErase(ps, ps->size - 1);
}

void SeqListPushFront(SeqList* ps, SLDataType x)
{
	SeqListInsert(ps, 0, x);
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}