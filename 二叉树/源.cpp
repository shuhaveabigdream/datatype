#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct item
{
	char date = 0;
	item*leftchild = NULL;
	item*rightchild = NULL;
}BiTNode,*BiTree;

typedef enum {Link,Thread}PointTag;

typedef struct elem
{	
	char date = 0;
	elem*leftchild, *rightchild;
	PointTag ltag;
	PointTag rtag;
}SearchTree,*SearchNode;

void CreateBiTree(BiTree *T)
{
	char ch;
	printf("输入该节点值(#为空):\n");
	fflush(stdin);
	scanf_s("%c", &ch);
	if (ch == '#')*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->date = ch;
		CreateBiTree(&(*T)->leftchild);
		CreateBiTree(&(*T)->rightchild);
	}
}

void CreateSearTree(SearchNode *T, char *s)
{
	static int index = 0;
	if (*(s + index) == '#')
	{
		*T = NULL;
		index++;
	}
	else
	{
		*T = (SearchNode)malloc(sizeof(SearchTree));
		(*T)->date = *(s + index++);
		CreateSearTree(&(*T)->leftchild, s);
		CreateSearTree(&(*T)->rightchild, s);
	}
}
SearchNode pre;
void add_Search(SearchNode T)
{
	if (T == NULL)
	{

	}
	else
	{
		add_Search(T->leftchild);
		if (T->leftchild != NULL)
		{
			T->ltag = Thread;
			T->leftchild = pre;
		}
		if (T->rightchild != NULL)
		{
			T->rtag = Thread;
			pre->rightchild = T;
		}
		pre = T;
		add_Search(T->rightchild);
	}
}

void CreateBiTree(BiTree *T,char *s)
{
	static int index = 0;
	if (*(s + index) == '#')
	{
		*T = NULL;
		index++;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->date = *(s + index++);
		CreateBiTree(&(*T)->leftchild, s);
		CreateBiTree(&(*T)->rightchild, s);
	}
}

void Q_bianli(BiTree T)
{
	if (T == NULL)
	{
		printf("#");
	}
	else
	{
		printf("%c", T->date);
		Q_bianli(T->leftchild);
		Q_bianli(T->rightchild);
	}
}

void M_bianli(BiTree T)
{
	if (T == NULL)
	{
		printf("#");
	}
	else
	{
		M_bianli(T->leftchild);
		printf("%c", T->date);
		M_bianli(T->rightchild);
	}
}

void B_bianli(BiTree T)
{
	if (T == NULL)
	{
		printf("#");
	}
	else
	{
		B_bianli(T->leftchild);
		B_bianli(T->rightchild);
		printf("%c", T->date);
	}
}

void main()
{
	BiTree t;
	SearchNode s;
	char x[20] = "ABDG###E##CF###";
	/*CreateBiTree(&t,x);
	printf("前序遍历\n");
	Q_bianli(t);
	printf("\n");
	printf("中序遍历\n");
	M_bianli(t);
	printf("\n");
	printf("后序遍历\n");
	B_bianli(t);*/
	CreateSearTree(&s,x);
	add_Search(s);
	_getch();
}