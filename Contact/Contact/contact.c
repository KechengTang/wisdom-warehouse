#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void CheckCapacity(Contact* pc)
{
	//���ݵĴ���
	if (pc->sz == pc->capacity)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (tmp != NULL)
		{
			pc->data = tmp;
		}
		else
		{
			perror("CheckCapacity::realloc");
			return;
		}
		pc->capacity += 2;
		printf("���ݳɹ���\n");
	}
}

//��̬�汾
//void InitContact(Contact* pc)
//{
//	assert(pc);
//
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//��̬�汾
//void InitContact(Contact* pc)
//{
//	assert(pc);
//
//	pc->sz = 0;
//	pc->capacity = DEFAULT_SZ;
//	pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));
//	if (pc->data == NULL)
//	{
//		perror("InitContact::malloc");
//		return;
//	}
//	memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));
//}
//

void LoadContact(Contact* pc)
{
	//���ļ�
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//���ļ�
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//��ʼ��ͨѶ¼�����ļ��汾
void InitContact(Contact* pc)
{
	assert(pc);

	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact::malloc");
		return;
	}
	memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));

	//�����ļ���Ϣ��ͨѶ¼��
	LoadContact(pc);
}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("���ٳɹ�\n");
}


void AddContact(Contact* pc)
{
	assert(pc);

	//��̬�汾
	/*if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}*/

	//��̬�汾
	CheckCapacity(pc);

	//¼����Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d",&(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ�\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);

	int i = 0;
	printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");

	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

//�ҵ������±꣬�Ҳ�������-1
int FindByName(const Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("ͨѶ¼�ѿգ��޷�ɾ��\n");
		return;
	}
	//ɾ��
	//1.�ҵ�
	char name[NAME_MAX] = {0};
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲����ڣ�\n");
		return;
	}
	//2.ɾ��
	int j = 0;
	for (j = pos; j < pc->sz-1; j++)
	{
		pc->data[j] = pc->data[j + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ���\n");
}

void SearchContact(const Contact* pc)
{
	assert(pc);

	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�����˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲����ڣ�\n");
		return;
	}
	printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	assert(pc);

	char name[NAME_MAX] = { 0 };
	int pos = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼�ѿգ��޷��޸ģ�\n");
		return;
	}
	printf("������Ҫ�޸ĵ��˵�����:>");
	scanf("%s", name);
	pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ����ݲ�����\n");
		return;
	}
	printf("������Ҫ�޸�ʲô��Ϣ(1-���֣�2-���䣬3-�Ա�4-�绰��5-סַ):>");
	int msg = 0;
	scanf("%d", &msg);
	switch(msg)
	{
	case 1:
		printf("�������µ�������>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("�������µ����䣺>");
		scanf("%d", &pc->data[pos].age);
		break;
	case 3:
		printf("�������µ��Ա�>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("�������µĵ绰��>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("�������µĵ�ַ��>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("���������޸�ʧ��\n");
		return;
	}
	printf("�޸ĳɹ���\n");
}

void ClearContact(Contact* pc)
{
	InitContact(pc);
}

void SortContact(Contact* pc)
{
	int i, j;
	PeoInfo tmp;
	for (int i = 0; i < pc->sz - 1; i++)
	{
		for (int j = 0; j < pc->sz - 1 - i; j++)
		{
			if (0 < strcmp(pc->data[j].name, pc->data[j + 1].name))
			{
				tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
			}
		}
	}
}

void SaveContact(const Contact* pc)
{
	//���ļ�
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data+i, sizeof(PeoInfo), 1, pf);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}