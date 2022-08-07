#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	SORT
};

void menu()
{
	printf("*******************************\n");
	printf("****** 1.add     2.del    *****\n");
	printf("****** 3.search  4.modify *****\n");
	printf("****** 5.show    6.clear  *****\n");
	printf("****** 7.sort    0.exit   *****\n");
	printf("*******************************\n");
}


void test()
{
	int input = 0;
	//创建通讯录
	Contact con;//通讯录
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}