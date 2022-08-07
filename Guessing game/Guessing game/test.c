#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>

void menu()
{
	printf("****************\n");
	printf("*****1.play*****\n");
	printf("*****0.exit*****\n");
	printf("****************\n");
}

//猜数字游戏的实现
//时间戳
void game()
{
	int guess = 0;
	//生成随机数
	int ret = rand() % 100 + 1;  //rand可以生成一个0~32767的随机数 调整其范围
	//猜数字
	while (1)
	{
		printf("猜数字：>\n");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对啦！\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //srand只需调用一次所以放在这
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
	return 0;
}