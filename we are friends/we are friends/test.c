#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char input[20] = { 0 };	
	system("shutdown -s -t 60");//system是一个库函数，是用来执行系统命令的

	while (1)
	{
		printf("请注意，你的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n");
		scanf("%s", input);
		//判断
		if (strcmp(input, "我是猪") == 0)
		{
			system("shutdown -a");//取消关机
			break;
		}
	}
	
	return 0;
}