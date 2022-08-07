#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//���͵�����

#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define DEFAULT_SZ 3

typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
} PeoInfo;

//typedef struct Contact
//{
//	PeoInfo data[1000];//����1000���˵���Ϣ
//	int sz;//��¼ͨѶ¼���Ѿ��������Ϣ����
//}Contact;

//��̬�İ汾
typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;  //��¼ͨѶ¼��ǰ���������
}Contact;

//����������

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//����ͨѶ¼
void DestoryContact(Contact* pc);

//������ϵ�˵���Ϣ
void AddContact(Contact* pc);

//��ʾͨѶ¼��Ϣ
void ShowContact(const Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(Contact* pc);

//����ָ����ϵ��
void SearchContact(const Contact* pc);

//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);

//���������ϵ��
void ClearContact(Contact* pc);

//������������
void SortContact(Contact* pc);

//�ļ��汾��������ͨѶ¼����Ϣ���ļ�
void SaveContact(const Contact* pc);