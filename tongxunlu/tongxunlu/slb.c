#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "windows.h"
#define MAXSIZE 20 //电话薄记录数量
#define MAX_SIZE 20 //人名的最大长度
#define HASHSIZE 53 //定义表长
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
	Record *elem[HASHSIZE]; //数据元素存储基址
	int count; //当前数据元素个数
	int size; //当前容量
} HashTable;
Status eq(NA x, NA y)
{
	//关键字比较，相等返回1；否则返回-1
	if (strcmp(x, y) == 0)
		return ok;
	else return error;
}
Status NUM_BER;

void getin(Record* a)
{
	//从键盘输入各记录
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


//建表，以电话号码为关键字，建立相应的散列表，并解决相应的冲突
void CreateHash2(HashTable* H, Record* a)
{
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
//在通讯录里查找电话号码关键字，若查找成功，显示信息//c用来记录冲突次数,查找成功时显示冲突次数
void SearchHash2(HashTable* H, int &c)
{
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
	printf("\n             3.  以电话号码建表                       ");
	printf("\n             4.  查找并显示给定电话号码的记录         ");
	printf("\n             5.  清空                                 ");
	printf("\n             6.  保存                                 ");
	printf("\n             7.  退出程序                             ");
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
			CreateHash2(H, a);   // 以电话号码建立散列表
			break;
		case 4:
			c = 0;
			SearchHash2(H, c);   //以电话号码查找数据
			break;
		case 5:
			Cls(a);
			break;
		case 6:
			Save();
			break;
		case 7:
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
