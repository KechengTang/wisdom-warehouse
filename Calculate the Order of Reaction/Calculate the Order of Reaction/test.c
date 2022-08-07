#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#define MAX 30 //定义输入的数据个数最大值（即最多计算MAX组数据）
#define dx 1e-3 //定义dx为一个极小的常量

//菜单函数
void menu()
{
	printf("*************************************\n");
	printf("***2022 TANG. All rights reserved.***\n");
	printf("*************************************\n");
	printf("*************计算反应级数*************\n");
	printf("***********请输入数据点的个数：");
}

//拉格朗日插值法
double LIP(double x1, int N, double* x, double * y) //Lagrange Interpolation Polynomial
{
	double y1 = 0.0;
	for (int i = 0; i < N; i++)
	{
		double m = 1.0;
		for (int j = 0; j < N; j++)
		{
			if (j != i)
			{
				m = m * (x1 - x[j]) / (x[i] - x[j]);
			}
		}
		y1 += m * y[i];
	}
	return y1;
}

//线性回归
void linear_regression(double* a, double* b, double* r, double* x, double* y, int N)
{
	double xy = 0.0, x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
	for (int i = 0; i < N; i++)
	{
		xy += x[i] * y[i];
		x1 += x[i];
		y1 += y[i];
		x2 += x[i] * x[i];
		y2 += y[i] * y[i];
	}
	*b = (xy - x1 * y1 / N) / (x2 - x1 * x1 / N);
	*a = y1 / N - *b * x1 / N;
	//需要时可用r验证相关性
	*r = (xy - x1 * y1 / N) / sqrt((x2 - x1 * x1 / N) * (y2 - y1 * y1 / N));
}



int main()
{
	double C[MAX] = { 0 }, t[MAX] = { 0 }; //用于存放浓度和时间数据的数组
	double x[MAX] = { 0 }, y[MAX] = { 0 }, v[MAX] = { 0 }; //用于存放一些计算出的值
	//菜单函数
	menu();

	//输入
	int N = 0; //N表示数据点的个数
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		printf("请输入第%d组的实验数据时间和浓度（两个数之间请以空格分隔）：", i+1);
		scanf("%lf %lf", &t[i], &C[i]);
		x[i] = t[i];
		y[i] = C[i];
	}

	//使用拉格朗日插值法和拆分法求各个时刻的速率
	for (int i = 0; i < N; i++)
	{
		//利用拉格朗日插值法求相邻点
		double x1 = x[i] - dx;
		double y1 = LIP(x1, N, &x, &y);
		double x2 = x[i] + dx;
		double y2 = LIP(x2, N, &x, &y);

		//差分法求斜率即求各点速率
		v[i] = (y1 - y2) / (2 * dx);
	}

	for (int i = 0; i < N; i++)
	{
		//同时取对数
		x[i] = log(C[i]);
		y[i] = log(v[i]);
	}

	//线性回归计算出拟合直线的参数a,b,r
	double a = 0, b = 0, r = 0;
	linear_regression(&a, &b, &r, &x, &y, N);

	//输出
	printf("反应级数 n = %lf:\n", b);
	printf("速率常数 k = %lf:\n", exp(a));  //速率常数为e的a次方

	return 0;
}

/*2022 TANG. All rights reserved.*/