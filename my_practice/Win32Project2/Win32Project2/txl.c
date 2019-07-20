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
//typedef struct person         /*创建结构体*/
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
//int find(pCon pcon, char *name)           /*比较函数输出*/
//{
//	int i = 0;
//	for (i = 0; i<pcon->count; i++)
//	{
//		if (strcmp((pcon->TelBook[i]).name, name) == 0)
//			return i;
//	}
//	return -1;
//}
//void add_peo(pCon pcon)     /*添加函数*/
//{
//	if ((pcon->count) == PERSON_MAX)
//		printf("通讯录已满，请删除后再添加。\n");
//	printf("姓名：");
//	scanf("%s", (pcon->TelBook[pcon->count]).name);
//	printf("城市：");
//	scanf("%s", (pcon->TelBook[pcon->count]).city);
//	printf("邮编：");
//	scanf("%d", &(pcon->TelBook[pcon->count]).eip);
//	printf("国家：");
//	scanf("%s", (pcon->TelBook[pcon->count]).state);
//	printf("街道：");
//	scanf("%s", (pcon->TelBook[pcon->count]).street);
//	pcon->count++;
//}
//void del_peo(pCon pcon)     /*删除函数*/
//{
//	int ret = 0;
//	char peoplename[NAME_MAX];
//	printf("请输入您要删除的联系人：");
//	scanf("%s", peoplename);
//	ret = find(pcon, peoplename);
//	if (ret == -1)
//	{
//		printf("联系人不存在。\n");
//	}
//	else
//	{
//		int j;
//		for (j = ret; j<pcon->count - 1; j++)
//		{
//			pcon->TelBook[j] = pcon->TelBook[j + 1];
//		}
//		printf("删除联系人成功。\n");
//	}
//	pcon->count--;
//}
//void search_peo(pCon pcon)       /*查找函数*/
//{
//	int ret = 0;
//	char peoplename[NAME_MAX];
//	printf("请输入您要查找的联系人：");
//	scanf("%s", peoplename);
//	ret = find(pcon, peoplename);
//	if (ret == -1)
//	{
//		printf("联系人不存在。\n");
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
//void modil_peo(pCon pcon)           /*修改函数*/
//{
//	int ret = 0;
//	char peoplename[NAME_MAX];
//	printf("请输入您要修改的联系人：");
//	scanf("%s", peoplename);
//	ret = find(pcon, peoplename);
//	if (ret == -1)
//	{
//		printf("联系人不存在。");
//	}
//	else
//	{
//		printf("姓名：");
//		scanf("%s", (pcon->TelBook[ret]).name);
//		printf("城市：");
//		scanf("%s", (pcon->TelBook[ret]).city);
//		printf("邮编：");
//		scanf("%d", &(pcon->TelBook[ret]).eip);
//		printf("国家：");
//		scanf("%s", (pcon->TelBook[ret]).state);
//		printf("街道：");
//		scanf("%s", (pcon->TelBook[ret]).street);
//	}
//}
//void show_peo(pCon pcon)         /*显示函数*/
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
//void clear_peo(pCon pcon)        /*清空函数*/
//{
//	pcon->count = 0;
//	printf("通讯录已清空。\n");
//}
//void print()          /*系统显示界面*/
//{
//	printf("    ************************************************************************\n");
//	printf("    ||                                                                    ||\n");
//	printf("    ||        1. 添加联系人        2. 删除联系人        3.查找联系人      ||\n");
//	printf("    ||        4. 修改联系人        5. 显示联系人        6.清空联系人      ||\n");
//	printf("    ||                                                                    ||\n");
//	printf("    ************************************************************************\n");
//}
//int main()        /*系统主函数*/
//{
//	struct contact my_contact;
//	int input;
//	my_contact.count = 0;
//	while (1)
//	{
//		print();
//		printf("请选择操作：");
//		scanf("%d", &input);
//		switch (input)            /*选择操作*/
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
//			printf("操作错误\n");
//			break;
//		}
//	}
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#define MAXSIZE  20                 //电话薄记录数量
#define MAX_SIZE 20                 //人名的最大长度
#define HASHSIZE 53                 //定义表长
#define ok 1
#define error -1
#define LEN sizeof(HashTable)
typedef int Status;
typedef char NA[MAX_SIZE];

typedef struct //记录
{
	NA name;
	NA tel;
	NA add;
} Record;

typedef struct
{//散列表
	Record *elem[HASHSIZE];                 //数据元素存储基址
	int count;                              //当前数据元素个数
	int size;                               //当前容量
} HashTable;

Status eq(NA x, NA y)
{
	//关键字比较，相等返回1；否则返回-1
	if (strcmp(x, y) == 0)
		return ok;
	else return error;
}

Status NUM_BER;                         //记录的个数

#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "windows.h"

void getin(Record* a)
{
	//键盘输入各人的信息
	printf("输入要添加的个数：\n");
	scanf("%d", &NUM_BER);
	int i;
	for (i = 0; i<NUM_BER; i++)
	{

		printf("请输入第%d个记录的用户名:\n", i + 1);
		scanf("%s", a[i].name);
		printf("请输入%d个记录的电话号码:\n", i + 1);
		scanf("%s", a[i].tel);
		printf("请输入第%d个记录的地址:\n", i + 1);
		scanf("%s", a[i].add);
	}
}

void ShowInformation(Record* a)         //显示输入的用户信息
{
	int i;
	for (i = 0; i<NUM_BER; i++)
		printf("\n第%d个用户信息:\n 姓名：%s\n 电话号码：%s\n 联系地址：%s\n", i + 1, a[i].name, a[i].tel, a[i].add);
}

void Cls(Record* a)
{//完成清屏操作
	printf("*");
	system("cls");
}
long fold(NA s)
{//人名的折叠处理
	char *p;
	long sum = 0;
	NA ss;
	strcpy(ss, s);                            //复制字符串，不改变原字符串的大小写
	strupr(ss);                              //将字符串ss转换为大写形式
	p = ss;
	while (*p != '\0')
		sum += *p++;
	printf("\n表的地址总数%d", sum);
	return sum;
}

int Hash1(NA str)
{//姓名建表的散列函数
	long n;
	int m;
	n = fold(str);                          //先将用户名进行折叠处理
	m = n%HASHSIZE;                         //折叠处理后的数，用除留余数法构造散列函数
	return m;                             //并返回模值
}

int Hash2(NA str)
{//电话号码建表的散列函数
	long n;
	int m;
	n = atoi(str);                        //把字符串转换成整型的函数.
	m = n%HASHSIZE;                         //用除留余数法构造散列函数
	return m;                             //并返回模值
}

Status collision(int p, int &c)
{//冲突处理函数，采用二次探测再散列法解决冲突
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
{//建表，以人的姓名为关键字，建立相应的散列表，并解决相应的冲突
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
				printf("第%d记录无法解决冲突", i + 1); //需要显示冲突次数时输出
				continue;
			}                                   //无法解决冲突，跳入下一循环(即+1)
		}
		H->elem[pp] = &(a[i]);                      //求得散列地址，将信息存入
		H->count++;
		printf("第%d个记录冲突次数为%d。\n", i + 1, c); //需要显示冲突次数时输出
	}
	printf("\n建表完成!\n此散列表容量为%d,当前表内存储的记录个数为%d.\n", HASHSIZE, H->count);
}

void SearchHash1(HashTable* H, int &c)
{//在通讯录里查找姓名关键字，若查找成功，显示信息//c用来显示冲突次数
	NA str;
	printf("\n请输入要查找记录的姓名：\n");
	scanf("%s", str);
	int p, pp;
	p = Hash1(str);
	pp = p;
	while ((H->elem[pp] != NULL) && (eq(str, H->elem[pp]->name) == -1))
		pp = collision(p, c);
	if (H->elem[pp] != NULL&&eq(str, H->elem[pp]->name) == 1)
	{
		printf("\n查找成功！\n查找过程冲突次数为%d．以下是您需要要查找的信息：\n\n", c);
		printf("姓  名：%s\n电话号码：%s\n联系地址：%s\n", H->elem[pp]->name, H->elem[pp]->tel, H->elem[pp]->add);
	}
	else printf("\n此人不存在，查找不成功!\n");
}

void CreateHash2(HashTable* H, Record* a)
{//建表，以电话号码为关键字，建立相应的散列表，并解决相应的冲突
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
				printf("第%d记录无法解决冲突", i + 1);   //需要显示冲突次数时输出
				continue;
			}                                      //无法解决冲突，跳入下一循环(即+1)
		}
		H->elem[pp] = &(a[i]);                      //求得散列地址，将信息存入
		H->count++;
		printf("第%d个记录冲突次数为%d。\n", i + 1, c);//需要显示冲突次数时输出
	}
	printf("\n建表完成!\n此散列表容量为%d,当前表内存储的记录个数为%d.\n", HASHSIZE, H->count);
}

void SearchHash2(HashTable* H, int &c)
{//在通讯录里查找电话号码关键字，若查找成功，显示信息//c用来记录冲突次数,查找成功时显示冲突次数
	NA tele;
	printf("\n请输入要查找记录的电话号码：\n");
	scanf("%s", tele);
	int p, pp;
	p = Hash2(tele);
	pp = p;
	while ((H->elem[pp] != NULL) && (eq(tele, H->elem[pp]->tel) == -1))
		pp = collision(p, c);
	if (H->elem[pp] != NULL&&eq(tele, H->elem[pp]->tel) == 1)
	{
		printf("\n查找成功！\n查找过程冲突次数为%d．以下是您需要要查找的信息：\n", c);
		printf("姓  名：%s\n电话号码：%s\n联系地址：%s\n", H->elem[pp]->name, H->elem[pp]->tel, H->elem[pp]->add);
	}
	else printf("\n此人不存在，查找不成功!\n");
}

void Save()
{//保存数据函数
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
	printf("                欢迎使用电话号码查找系统             ");
	printf("\n             1.  添加用户信息                         ");
	printf("\n             2.  读取所有用户信息                     ");
	printf("\n             3.  以姓名建表                           ");
	printf("\n             4.  以电话号码建表                       ");
	printf("\n             5.  查找并显示给定用户名的记录           ");
	printf("\n             6.  查找并显示给定电话号码的记录         ");
	printf("\n             7.  清空                                 ");
	printf("\n             8.  保存                                 ");
	printf("\n             9.  退出程序                             ");
	printf("\n       注意：                                         ");
	printf("\n             Ⅰ.进行5操作前 请先输出3               ");
	printf("\n             Ⅱ.进行6操作前 请先输出4               ");
	printf("\n");
	printf("请输入你想要的操作：");
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
			CreateHash1(H, a);   // 以姓名建立散列表
			break;
		case 4:
			CreateHash2(H, a);   // 以电话号码建立散列表
			break;
		case 5:
			c = 0;
			SearchHash1(H, c);   //以姓名查找数据
			break;
		case 6:
			c = 0;
			SearchHash2(H, c);   //以电话号码查找数据
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
			printf("输入错误，请重新输入!");
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
