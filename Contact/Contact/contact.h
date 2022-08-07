#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//类型的声明

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
//	PeoInfo data[1000];//储存1000个人的信息
//	int sz;//记录通讯录中已经保存的信息个数
//}Contact;

//动态的版本
typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;  //记录通讯录当前的最大容量
}Contact;

//函数的声明

//初始化通讯录
void InitContact(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);

//增加联系人的信息
void AddContact(Contact* pc);

//显示通讯录信息
void ShowContact(const Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//清空所有联系人
void ClearContact(Contact* pc);

//按照名字排序
void SortContact(Contact* pc);

//文件版本——保存通讯录的信息到文件
void SaveContact(const Contact* pc);