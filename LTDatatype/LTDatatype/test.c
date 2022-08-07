#include <stdio.h>
#include "test.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	return head;
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListDestroy(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_prev);
}

void ListPopFront(ListNode* pHead)
{
	ListErase(pHead->_next);
}

voidListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	prev->_next = newnode;
	newnode->_next = pos;
	newnode->_prev = prev;
	pos->_prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}