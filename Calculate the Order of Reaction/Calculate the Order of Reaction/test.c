#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#define MAX 30 //������������ݸ������ֵ����������MAX�����ݣ�
#define dx 1e-3 //����dxΪһ����С�ĳ���

//�˵�����
void menu()
{
	printf("*************************************\n");
	printf("***2022 TANG. All rights reserved.***\n");
	printf("*************************************\n");
	printf("*************���㷴Ӧ����*************\n");
	printf("***********���������ݵ�ĸ�����");
}

//�������ղ�ֵ��
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

//���Իع�
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
	//��Ҫʱ����r��֤�����
	*r = (xy - x1 * y1 / N) / sqrt((x2 - x1 * x1 / N) * (y2 - y1 * y1 / N));
}



int main()
{
	double C[MAX] = { 0 }, t[MAX] = { 0 }; //���ڴ��Ũ�Ⱥ�ʱ�����ݵ�����
	double x[MAX] = { 0 }, y[MAX] = { 0 }, v[MAX] = { 0 }; //���ڴ��һЩ�������ֵ
	//�˵�����
	menu();

	//����
	int N = 0; //N��ʾ���ݵ�ĸ���
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		printf("�������%d���ʵ������ʱ���Ũ�ȣ�������֮�����Կո�ָ�����", i+1);
		scanf("%lf %lf", &t[i], &C[i]);
		x[i] = t[i];
		y[i] = C[i];
	}

	//ʹ���������ղ�ֵ���Ͳ�ַ������ʱ�̵�����
	for (int i = 0; i < N; i++)
	{
		//�����������ղ�ֵ�������ڵ�
		double x1 = x[i] - dx;
		double y1 = LIP(x1, N, &x, &y);
		double x2 = x[i] + dx;
		double y2 = LIP(x2, N, &x, &y);

		//��ַ���б�ʼ����������
		v[i] = (y1 - y2) / (2 * dx);
	}

	for (int i = 0; i < N; i++)
	{
		//ͬʱȡ����
		x[i] = log(C[i]);
		y[i] = log(v[i]);
	}

	//���Իع��������ֱ�ߵĲ���a,b,r
	double a = 0, b = 0, r = 0;
	linear_regression(&a, &b, &r, &x, &y, N);

	//���
	printf("��Ӧ���� n = %lf:\n", b);
	printf("���ʳ��� k = %lf:\n", exp(a));  //���ʳ���Ϊe��a�η�

	return 0;
}

/*2022 TANG. All rights reserved.*/