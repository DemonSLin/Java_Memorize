//#define _CRT_SECURE_NO_WARNINGS
//#ifndef _CONTACT__
//#define _CONTACT__
//#define NAME_MAX 20
//#define CITY_MAX 20
//#define EIP_MAX 6
//#define STREET_MAX 20
//#define STATE_MAX 20
//#define PERSON_MAX 1000
//#include <stdio.h>
//#include <string.h>
//#endif 
//
//typedef struct person         /*�����ṹ��*/
//{
//	char name[NAME_MAX];
//	char city[CITY_MAX];
//	int eip;
//	char street[STREET_MAX];
//	char state[STATE_MAX];
//}*pPerson;
//typedef struct contact
//{
//	struct person TelBook[PERSON_MAX];
//	int count;
//}*pCon;
//void add_peo(pCon pcon);
//void del_peo(pCon pcon);
//void search_peo(pCon pcon);
//void modil_peo(pCon pcon);
//void show_peo(pCon pcon);
//void clear_peo(pCon pcon);
//int find(pCon pcon, char *name)           /*�ȽϺ������*/
//{
//	int i = 0;
//	for (i = 0; i<pcon->count; i++)
//	{
//		if (strcmp((pcon->TelBook[i]).name, name) == 0)
//			return i;
//	}
//	return -1;
//}
//void add_peo(pCon pcon)     /*��Ӻ���*/
//{
//	if ((pcon->count) == PERSON_MAX)
//		printf("ͨѶ¼��������ɾ��������ӡ�\n");
//	printf("������");
//	scanf("%s", (pcon->TelBook[pcon->count]).name);
//	printf("���У�");
//	scanf("%s", (pcon->TelBook[pcon->count]).city);
//	printf("�ʱࣺ");
//	scanf("%d", &(pcon->TelBook[pcon->count]).eip);
//	printf("���ң�");
//	scanf("%s", (pcon->TelBook[pcon->count]).state);
//	printf("�ֵ���");
//	scanf("%s", (pcon->TelBook[pcon->count]).street);
//	pcon->count++;
//}
//void del_peo(pCon pcon)     /*ɾ������*/
//{
//	int ret = 0;
//	char peoplename[NAME_MAX];
//	printf("��������Ҫɾ������ϵ�ˣ�");
//	scanf("%s", peoplename);
//	ret = find(pcon, peoplename);
//	if (ret == -1)
//	{
//		printf("��ϵ�˲����ڡ�\n");
//	}
//	else
//	{
//		int j;
//		for (j = ret; j<pcon->count - 1; j++)
//		{
//			pcon->TelBook[j] = pcon->TelBook[j + 1];
//		}
//		printf("ɾ����ϵ�˳ɹ���\n");
//	}
//	pcon->count--;
//}
//void search_peo(pCon pcon)       /*���Һ���*/
//{
//	int ret = 0;
//	char peoplename[NAME_MAX];
//	printf("��������Ҫ���ҵ���ϵ�ˣ�");
//	scanf("%s", peoplename);
//	ret = find(pcon, peoplename);
//	if (ret == -1)
//	{
//		printf("��ϵ�˲����ڡ�\n");
//	}
//	else
//	{
//		printf(" %s\t", (pcon->TelBook[ret]).name);
//		printf(" %s\t", (pcon->TelBook[ret]).city);
//		printf(" %d\t", (pcon->TelBook[ret]).eip);
//		printf(" %s\t", (pcon->TelBook[ret]).state);
//		printf(" %s\n", (pcon->TelBook[ret]).street);
//	}
//}
//void modil_peo(pCon pcon)           /*�޸ĺ���*/
//{
//	int ret = 0;
//	char peoplename[NAME_MAX];
//	printf("��������Ҫ�޸ĵ���ϵ�ˣ�");
//	scanf("%s", peoplename);
//	ret = find(pcon, peoplename);
//	if (ret == -1)
//	{
//		printf("��ϵ�˲����ڡ�");
//	}
//	else
//	{
//		printf("������");
//		scanf("%s", (pcon->TelBook[ret]).name);
//		printf("���У�");
//		scanf("%s", (pcon->TelBook[ret]).city);
//		printf("�ʱࣺ");
//		scanf("%d", &(pcon->TelBook[ret]).eip);
//		printf("���ң�");
//		scanf("%s", (pcon->TelBook[ret]).state);
//		printf("�ֵ���");
//		scanf("%s", (pcon->TelBook[ret]).street);
//	}
//}
//void show_peo(pCon pcon)         /*��ʾ����*/
//{
//	int i;
//	for (i = 0; i<pcon->count; i++)
//	{
//		printf(" %d.%s\t", i + 1, (pcon->TelBook[i]).name);
//		printf(" %s\t", (pcon->TelBook[i]).city);
//		printf(" %d\t", (pcon->TelBook[i]).eip);
//		printf(" %s\t", (pcon->TelBook[i]).state);
//		printf(" %s\n", (pcon->TelBook[i]).street);
//	}
//}
//void clear_peo(pCon pcon)        /*��պ���*/
//{
//	pcon->count = 0;
//	printf("ͨѶ¼����ա�\n");
//}
//void print()          /*ϵͳ��ʾ����*/
//{
//	printf("    ************************************************************************\n");
//	printf("    ||                                                                    ||\n");
//	printf("    ||        1. �����ϵ��        2. ɾ����ϵ��        3.������ϵ��      ||\n");
//	printf("    ||        4. �޸���ϵ��        5. ��ʾ��ϵ��        6.�����ϵ��      ||\n");
//	printf("    ||                                                                    ||\n");
//	printf("    ************************************************************************\n");
//}
//int main()        /*ϵͳ������*/
//{
//	struct contact my_contact;
//	int input;
//	my_contact.count = 0;
//	while (1)
//	{
//		print();
//		printf("��ѡ�������");
//		scanf("%d", &input);
//		switch (input)            /*ѡ�����*/
//		{
//		case 1:
//			add_peo(&my_contact);
//			break;
//		case 2:
//			del_peo(&my_contact);
//			break;
//		case 3:
//			search_peo(&my_contact);
//			break;
//		case 4:
//			modil_peo(&my_contact);
//			break;
//		case 5:
//			show_peo(&my_contact);
//			break;
//		case 6:
//			clear_peo(&my_contact);
//			break;
//		default:
//			printf("��������\n");
//			break;
//		}
//	}
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#define MAXSIZE  20                 //�绰����¼����
#define MAX_SIZE 20                 //��������󳤶�
#define HASHSIZE 53                 //�����
#define ok 1
#define error -1
#define LEN sizeof(HashTable)
typedef int Status;
typedef char NA[MAX_SIZE];

typedef struct //��¼
{
	NA name;
	NA tel;
	NA add;
} Record;

typedef struct
{//ɢ�б�
	Record *elem[HASHSIZE];                 //����Ԫ�ش洢��ַ
	int count;                              //��ǰ����Ԫ�ظ���
	int size;                               //��ǰ����
} HashTable;

Status eq(NA x, NA y)
{
	//�ؼ��ֱȽϣ���ȷ���1�����򷵻�-1
	if (strcmp(x, y) == 0)
		return ok;
	else return error;
}

Status NUM_BER;                         //��¼�ĸ���

#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "windows.h"

void getin(Record* a)
{
	//����������˵���Ϣ
	printf("����Ҫ��ӵĸ�����\n");
	scanf("%d", &NUM_BER);
	int i;
	for (i = 0; i<NUM_BER; i++)
	{

		printf("�������%d����¼���û���:\n", i + 1);
		scanf("%s", a[i].name);
		printf("������%d����¼�ĵ绰����:\n", i + 1);
		scanf("%s", a[i].tel);
		printf("�������%d����¼�ĵ�ַ:\n", i + 1);
		scanf("%s", a[i].add);
	}
}

void ShowInformation(Record* a)         //��ʾ������û���Ϣ
{
	int i;
	for (i = 0; i<NUM_BER; i++)
		printf("\n��%d���û���Ϣ:\n ������%s\n �绰���룺%s\n ��ϵ��ַ��%s\n", i + 1, a[i].name, a[i].tel, a[i].add);
}

void Cls(Record* a)
{//�����������
	printf("*");
	system("cls");
}
long fold(NA s)
{//�������۵�����
	char *p;
	long sum = 0;
	NA ss;
	strcpy(ss, s);                            //�����ַ��������ı�ԭ�ַ����Ĵ�Сд
	strupr(ss);                              //���ַ���ssת��Ϊ��д��ʽ
	p = ss;
	while (*p != '\0')
		sum += *p++;
	printf("\n��ĵ�ַ����%d", sum);
	return sum;
}

int Hash1(NA str)
{//���������ɢ�к���
	long n;
	int m;
	n = fold(str);                          //�Ƚ��û��������۵�����
	m = n%HASHSIZE;                         //�۵������������ó�������������ɢ�к���
	return m;                             //������ģֵ
}

int Hash2(NA str)
{//�绰���뽨���ɢ�к���
	long n;
	int m;
	n = atoi(str);                        //���ַ���ת�������͵ĺ���.
	m = n%HASHSIZE;                         //�ó�������������ɢ�к���
	return m;                             //������ģֵ
}

Status collision(int p, int &c)
{//��ͻ�����������ö���̽����ɢ�з������ͻ
	int i, q;
	i = c / 2 + 1;
	while (i<HASHSIZE)
	{
		if (c % 2 == 0)
		{
			c++;
			q = (p + i*i) % HASHSIZE;
			if (q >= 0) return q;
			else i = c / 2 + 1;
		}
		else
		{
			q = (p - i*i) % HASHSIZE;
			c++;
			if (q >= 0) return q;
			else i = c / 2 + 1;
		}
	}
	return error;
}

void CreateHash1(HashTable* H, Record* a)
{//�������˵�����Ϊ�ؼ��֣�������Ӧ��ɢ�б��������Ӧ�ĳ�ͻ
	int i, p = -1, c, pp;
	for (i = 0; i<NUM_BER; i++)
	{
		c = 0;
		p = Hash1(a[i].name);
		pp = p;
		while (H->elem[pp] != NULL)
		{
			pp = collision(p, c);
			if (pp<0)
			{
				printf("��%d��¼�޷������ͻ", i + 1); //��Ҫ��ʾ��ͻ����ʱ���
				continue;
			}                                   //�޷������ͻ��������һѭ��(��+1)
		}
		H->elem[pp] = &(a[i]);                      //���ɢ�е�ַ������Ϣ����
		H->count++;
		printf("��%d����¼��ͻ����Ϊ%d��\n", i + 1, c); //��Ҫ��ʾ��ͻ����ʱ���
	}
	printf("\n�������!\n��ɢ�б�����Ϊ%d,��ǰ���ڴ洢�ļ�¼����Ϊ%d.\n", HASHSIZE, H->count);
}

void SearchHash1(HashTable* H, int &c)
{//��ͨѶ¼����������ؼ��֣������ҳɹ�����ʾ��Ϣ//c������ʾ��ͻ����
	NA str;
	printf("\n������Ҫ���Ҽ�¼��������\n");
	scanf("%s", str);
	int p, pp;
	p = Hash1(str);
	pp = p;
	while ((H->elem[pp] != NULL) && (eq(str, H->elem[pp]->name) == -1))
		pp = collision(p, c);
	if (H->elem[pp] != NULL&&eq(str, H->elem[pp]->name) == 1)
	{
		printf("\n���ҳɹ���\n���ҹ��̳�ͻ����Ϊ%d������������ҪҪ���ҵ���Ϣ��\n\n", c);
		printf("��  ����%s\n�绰���룺%s\n��ϵ��ַ��%s\n", H->elem[pp]->name, H->elem[pp]->tel, H->elem[pp]->add);
	}
	else printf("\n���˲����ڣ����Ҳ��ɹ�!\n");
}

void CreateHash2(HashTable* H, Record* a)
{//�����Ե绰����Ϊ�ؼ��֣�������Ӧ��ɢ�б��������Ӧ�ĳ�ͻ
	int i, p = -1, c, pp;
	for (i = 0; i<NUM_BER; i++)
	{
		c = 0;
		p = Hash2(a[i].tel);
		pp = p;
		while (H->elem[pp] != NULL)
		{
			pp = collision(p, c);
			if (pp<0)
			{
				printf("��%d��¼�޷������ͻ", i + 1);   //��Ҫ��ʾ��ͻ����ʱ���
				continue;
			}                                      //�޷������ͻ��������һѭ��(��+1)
		}
		H->elem[pp] = &(a[i]);                      //���ɢ�е�ַ������Ϣ����
		H->count++;
		printf("��%d����¼��ͻ����Ϊ%d��\n", i + 1, c);//��Ҫ��ʾ��ͻ����ʱ���
	}
	printf("\n�������!\n��ɢ�б�����Ϊ%d,��ǰ���ڴ洢�ļ�¼����Ϊ%d.\n", HASHSIZE, H->count);
}

void SearchHash2(HashTable* H, int &c)
{//��ͨѶ¼����ҵ绰����ؼ��֣������ҳɹ�����ʾ��Ϣ//c������¼��ͻ����,���ҳɹ�ʱ��ʾ��ͻ����
	NA tele;
	printf("\n������Ҫ���Ҽ�¼�ĵ绰���룺\n");
	scanf("%s", tele);
	int p, pp;
	p = Hash2(tele);
	pp = p;
	while ((H->elem[pp] != NULL) && (eq(tele, H->elem[pp]->tel) == -1))
		pp = collision(p, c);
	if (H->elem[pp] != NULL&&eq(tele, H->elem[pp]->tel) == 1)
	{
		printf("\n���ҳɹ���\n���ҹ��̳�ͻ����Ϊ%d������������ҪҪ���ҵ���Ϣ��\n", c);
		printf("��  ����%s\n�绰���룺%s\n��ϵ��ַ��%s\n", H->elem[pp]->name, H->elem[pp]->tel, H->elem[pp]->add);
	}
	else printf("\n���˲����ڣ����Ҳ��ɹ�!\n");
}

void Save()
{//�������ݺ���
	FILE *fp;
	if ((fp = fopen("c:\test.txt", "w")) == NULL)
	{
		printf("\nERROR opening customet file");
	}
	fclose(fp);
}
int main(int argc, char* argv[])
{
	int c, flag = 1;
	HashTable *H;
	H = (HashTable*)malloc(LEN);
	for (int i = 0; i<HASHSIZE; i++)
		H->elem[i] = NULL;
	H->size = HASHSIZE;
	H->count = 0;
	Record a[MAXSIZE];
	printf("                ��ӭʹ�õ绰�������ϵͳ             ");
	printf("\n             1.  ����û���Ϣ                         ");
	printf("\n             2.  ��ȡ�����û���Ϣ                     ");
	printf("\n             3.  ����������                           ");
	printf("\n             4.  �Ե绰���뽨��                       ");
	printf("\n             5.  ���Ҳ���ʾ�����û����ļ�¼           ");
	printf("\n             6.  ���Ҳ���ʾ�����绰����ļ�¼         ");
	printf("\n             7.  ���                                 ");
	printf("\n             8.  ����                                 ");
	printf("\n             9.  �˳�����                             ");
	printf("\n       ע�⣺                                         ");
	printf("\n             ��.����5����ǰ �������3               ");
	printf("\n             ��.����6����ǰ �������4               ");
	printf("\n");
	printf("����������Ҫ�Ĳ�����");
	printf("\n");
	while (1)
	{

		int num;
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			getin(a);
			break;
		case 2:
			ShowInformation(a);
			break;
		case 3:
			CreateHash1(H, a);   // ����������ɢ�б�
			break;
		case 4:
			CreateHash2(H, a);   // �Ե绰���뽨��ɢ�б�
			break;
		case 5:
			c = 0;
			SearchHash1(H, c);   //��������������
			break;
		case 6:
			c = 0;
			SearchHash2(H, c);   //�Ե绰�����������
			break;
		case 7:
			Cls(a);
			break;
		case 8:
			Save();
			break;
		case 9:
			return 0;
			break;
		default:
			printf("�����������������!");
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
