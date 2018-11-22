/*
	单链表练习
*/
#include<stdio.h>
#include<stdlib.h>
//单链表定义
typedef struct Node
{
	int data;
	struct Node * next;
}Node,*Linkedlist;
//链表长度查询
int listlength(Linkedlist L)
{
	Node * p;
	int j = 0;
	p = L->next;
	while(p != NULL)
	{
		j++;
		p = p->next;
	}
	return j;

}
//初始化空链表
Linkedlist initlist(Linkedlist L)
{
	L = (Linkedlist)malloc(sizeof(Node));
	L->next = NULL;
	return L;
}
//头插法
Linkedlist CreateFromHead(Linkedlist L)
{
	//flag为插入标志，为0时停止插入
	int flag = 1;
	Node* s;
	char c;
	while(flag == 1)
	{
		c = getchar();
		if(c != '$')
			{
				s = (Node*)malloc(sizeof(Node));
				s->data = c;
				s->next = L->next;
				L->next = s;
			}
		else flag = 0;
	}
	return L;
}
//尾插法
Linkedlist CreateFromTail(Linkedlist L)
{
	int flag = 1;
	Node* s,* t;
	char c;
	t = L;
	while(flag == 1)
	{
		c = getchar();
		if(c != '$')
			{
				s = (Node*)malloc(sizeof(Node));
				s->data = c;
				t->next = s;
				t = s;
				
			}
		else flag = 0;
		t->next = NULL;
	}
	return L;
}

int main()
{	
	Linkedlist L = initlist(L);
//	Linkedlist S = CreateFromHead(L);
	Linkedlist T = CreateFromTail(L);
/*	while(S->next != NULL){
		printf("%c\n",S->data);
		S = S->next;}
	printf("%c\n",S->data);*/

	while(T->next != NULL){
		printf("%c\n",T->data);
		T = T->next;}
	printf("%c\n",T->data);
	return 0;
}
