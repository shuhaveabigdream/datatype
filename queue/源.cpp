#include <stdio.h>
#include <malloc.h>
#include <conio.h>
//队列数据格式

#define MAX_SIZE 10

typedef struct item
{
	int data = 0;
	item*next = NULL;
}LinkNode,*NodePtr;

typedef struct elem//需要队列头和队列尾部
{
	NodePtr head = NULL;
	NodePtr tear = NULL;
	int lenth = 0;//队列长度
}LinkQueue;

typedef struct ls//数组实现的静态队列
{
	int buffer[MAX_SIZE];
	int head = 0;//头指针
	int tear = -1;//尾部指针
	int count = 0;//元素个数
}Queue;

bool EnQueue(Queue* Qu,int date)//静态队列入
{
	if (Qu->count > MAX_SIZE)return 0;//数据满了返回0
	if (++Qu->tear > MAX_SIZE - 1)Qu->tear = 0;//尾部溢出则指向头部
	Qu->buffer[Qu->tear] = date;
	Qu->count++;
	return	1;
}

bool DeQueue(Queue* Qu, int *date)//静态队列出
{
	if (Qu->count == 0)return 0;//空队列返回0
	if (++Qu->head > MAX_SIZE - 1)Qu->head = 0;
	Qu->count--;
	return 1;
}

bool bianli(Queue *Qu)//遍历静态队列
{
	if (Qu->count == 0)return 0;//队列为空则返回0
	int ptr = Qu->head;
	for (int i = 0; i < Qu->count; i++)
	{
		if (ptr + i>MAX_SIZE - 1)ptr = -i;
		printf("[%d]:%d\n",i,Qu->buffer[ptr+i]);
	}
	return 1;
}

bool EnQueue(LinkQueue* Qu,int date)//入队列
{
	NodePtr e = (NodePtr)malloc(sizeof(LinkNode));
	e->data = date;
	e->next = NULL;
	if (Qu->tear == NULL)//如果队列为空 也可以判断lenth
	{
		Qu->head = e;
		Qu->tear = e;
		Qu->lenth = 1;
	}
	else
	{
		Qu->tear->next = e;
		Qu->tear = e;
		Qu->lenth++;//长度自加一位
	}
	return 1;
}

bool DeQueue(LinkQueue*Qu, int*date)//出队列
{
	if (Qu->lenth == 0)return 0;//空队列
	NodePtr temp = Qu->head;
	*date = temp->data;
	if (Qu->head == Qu->tear)//也可以判断lenth为0
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