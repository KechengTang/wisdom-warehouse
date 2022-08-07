typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

ListNode* ListCreate();

void ListPrint(ListNode* pHead);

void ListDestroy(ListNode* pHead);

void ListPushBack(ListNode* pHead, LTDataType x);

void ListPopBack(ListNode* pHead);

void ListPushFront(ListNode* pHead, LTDataType x);

void ListPopFront(ListNode* pHead);

ListNode* ListFind(ListNode* pHead, LTDataType x);

void ListInsert(ListNode* pos, LTDataType x);

void ListErase(ListNode* pos);