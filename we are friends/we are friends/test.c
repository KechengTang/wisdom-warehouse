#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char input[20] = { 0 };	
	system("shutdown -s -t 60");//system��һ���⺯����������ִ��ϵͳ�����

	while (1)
	{
		printf("��ע�⣬��ĵ�����1�����ڹػ���������룺����������ȡ���ػ�\n");
		scanf("%s", input);
		//�ж�
		if (strcmp(input, "������") == 0)
		{
			system("shutdown -a");//ȡ���ػ�
			break;
		}
	}
	
	return 0;
}