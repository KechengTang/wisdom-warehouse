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

//��������Ϸ��ʵ��
//ʱ���
void game()
{
	int guess = 0;
	//���������
	int ret = rand() % 100 + 1;  //rand��������һ��0~32767������� �����䷶Χ
	//������
	while (1)
	{
		printf("�����֣�>\n");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("��С��\n");
		}
		else if (guess > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬�¶�����\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //srandֻ�����һ�����Է�����
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}