#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "windows.h"
#define MAXSIZE 20 //�绰����¼����
#define MAX_SIZE 20 //��������󳤶�
#define HASHSIZE 53 //�����
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
	Record *elem[HASHSIZE]; //����Ԫ�ش洢��ַ
	int count; //��ǰ����Ԫ�ظ���
	int size; //��ǰ����
} HashTable;
Status eq(NA x, NA y)
{
	//�ؼ��ֱȽϣ���ȷ���1�����򷵻�-1
	if (strcmp(x, y) == 0)
		return ok;
	else return error;
}
Status NUM_BER;

void getin(Record* a)
{
	//�Ӽ����������¼
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


//�����Ե绰����Ϊ�ؼ��֣�������Ӧ��ɢ�б��������Ӧ�ĳ�ͻ
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
//��ͨѶ¼����ҵ绰����ؼ��֣������ҳɹ�����ʾ��Ϣ//c������¼��ͻ����,���ҳɹ�ʱ��ʾ��ͻ����
void SearchHash2(HashTable* H, int &c)
{
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
	printf("\n             3.  �Ե绰���뽨��                       ");
	printf("\n             4.  ���Ҳ���ʾ�����绰����ļ�¼         ");
	printf("\n             5.  ���                                 ");
	printf("\n             6.  ����                                 ");
	printf("\n             7.  �˳�����                             ");
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
			CreateHash2(H, a);   // �Ե绰���뽨��ɢ�б�
			break;
		case 4:
			c = 0;
			SearchHash2(H, c);   //�Ե绰�����������
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
			printf("�����������������!");
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
