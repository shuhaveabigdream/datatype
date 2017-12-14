#include <stdio.h>
#include <malloc.h>
#include <conio.h>
//�������ݸ�ʽ

#define MAX_SIZE 10

typedef struct item
{
	int data = 0;
	item*next = NULL;
}LinkNode,*NodePtr;

typedef struct elem//��Ҫ����ͷ�Ͷ���β��
{
	NodePtr head = NULL;
	NodePtr tear = NULL;
	int lenth = 0;//���г���
}LinkQueue;

typedef struct ls//����ʵ�ֵľ�̬����
{
	int buffer[MAX_SIZE];
	int head = 0;//ͷָ��
	int tear = -1;//β��ָ��
	int count = 0;//Ԫ�ظ���
}Queue;

bool EnQueue(Queue* Qu,int date)//��̬������
{
	if (Qu->count > MAX_SIZE)return 0;//�������˷���0
	if (++Qu->tear > MAX_SIZE - 1)Qu->tear = 0;//β�������ָ��ͷ��
	Qu->buffer[Qu->tear] = date;
	Qu->count++;
	return	1;
}

bool DeQueue(Queue* Qu, int *date)//��̬���г�
{
	if (Qu->count == 0)return 0;//�ն��з���0
	if (++Qu->head > MAX_SIZE - 1)Qu->head = 0;
	Qu->count--;
	return 1;
}

bool bianli(Queue *Qu)//������̬����
{
	if (Qu->count == 0)return 0;//����Ϊ���򷵻�0
	int ptr = Qu->head;
	for (int i = 0; i < Qu->count; i++)
	{
		if (ptr + i>MAX_SIZE - 1)ptr = -i;
		printf("[%d]:%d\n",i,Qu->buffer[ptr+i]);
	}
	return 1;
}

bool EnQueue(LinkQueue* Qu,int date)//�����
{
	NodePtr e = (NodePtr)malloc(sizeof(LinkNode));
	e->data = date;
	e->next = NULL;
	if (Qu->tear == NULL)//�������Ϊ�� Ҳ�����ж�lenth
	{
		Qu->head = e;
		Qu->tear = e;
		Qu->lenth = 1;
	}
	else
	{
		Qu->tear->next = e;
		Qu->tear = e;
		Qu->lenth++;//�����Լ�һλ
	}
	return 1;
}

bool DeQueue(LinkQueue*Qu, int*date)//������
{
	if (Qu->lenth == 0)return 0;//�ն���
	NodePtr temp = Qu->head;
	*date = temp->data;
	if (Qu->head == Qu->tear)//Ҳ�����ж�lenthΪ0
	{
		Qu->head = NULL;
		Qu->tear = NULL;
	}
	else
	{
		Qu->head = Qu->head->next;
	}
	Qu->lenth--;
	free(temp);
	return 1;
}

void main()
{
	Queue m;
	int temp = 0;
	for (int i = 0; i < 10;i++)EnQueue(&m, i+1);
	_getch();
}