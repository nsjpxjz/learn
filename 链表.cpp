#include <stdio.h>/*该文件包含printf()等函数*/
#include <stdlib.h>/*该文件包含exit()等函数*/
#include <malloc.h>/*该文件包含malloc()等函数*/

typedef int DataType;/*定义DataType为int*/


typedef struct Node
{
	DataType data;
	struct Node *next;
} SLNode;

void ListInitiate(SLNode **head)/*初始化*/
{
	/*如果有内存空间，申请头结点空间并使头指针head指向头结点*/
	if((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
	(*head)->next = NULL;/*置链尾标记NULL */
}

int ListLength(SLNode *head)               /* 单链表的长度*/
{
	SLNode *p = head;/*p指向首元结点*/
	int size = 0;/*size初始为0*/
	
	while(p->next != NULL)/*循环计数*/
	{
	p = p->next;
	size ++;
	}
	return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*在带头结点的单链表head的数据元素ai（0 ≤ i ≤ size）结点前*/
/*插入一个存放数据元素x的结点*/
{
SLNode *p, *q;
int j;

p = head; /*p指向首元结点*/
j = -1;/*j初始为-1*/
while(p->next != NULL && j < i - 1) 
/*最终让指针p指向数据元素ai-1结点*/
{
p = p->next;
j++;
}

if(j != i - 1)
{
printf("插入位置参数错！");
return 0;
}

/*生成新结点由指针q指示*/
if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
q->data = x;

//此段程序有一处错误
q->next = p->next;/*给指针q->next赋值*/
p->next = q;/*给指针p->next重新赋值*/
return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*删除带头结点的单链表head的数据元素ai（0 ≤ i ≤ size - 1）结点*/
/*删除结点的数据元素域值由x带回。删除成功时返回1；失败返回0*/
{
SLNode *p, *s;
int j;

p = head; /*p指向首元结点*/
j = -1;/*j初始为-1*/
while(p->next != NULL && p->next->next!= NULL && j < i - 1) 
/*最终让指针p指向数据元素ai-1结点*/
{
p = p->next;
j++;
}

if(j != i - 1)
{
printf("删除位置参数错！");
return 0;
}

//此段程序有一处错误
s=p->next; /*指针s指向数据元素ai结点*/
*x = s->data;/*把指针s所指结点的数据元素域值赋予x*/
p->next = s->next;/*把数据元素ai结点从单链表中删除*/
free(s);/*释放指针s所指结点的内存空间*/
return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*取数据元素ai和删除函数类同，只是不删除数据元素ai结点*/
{
SLNode *p;
int j;

p = head;
j = -1;
while(p->next != NULL && j < i)
{
p = p->next;j++;
}

if(j != i)
{
printf("取元素位置参数错！");
return 0;
}

//此段程序有一处错误
*x = p->data;
return 1;
}

void Destroy(SLNode **head)
{
SLNode *p, *p1;

p = *head;
while(p != NULL)
{
p1 = p;
p = p->next;
free(p1);
}
*head = NULL;
}
void Mergelist(SLNode *head1,SLNode *head2,SLNode **head3)
{
	SLNode *p,*q,*m;
	p=head1->next;q=head2->next;
	*head3=head1;m=*head3;
	while(p&&q)
	{
		if (p->data<q->data)
		{
			m->next=p;
			m=p;
			p=p->next;
		}
		else
		{
			m->next=q;
			m=q;
			q=q->next;
		}
	if (p) m->next=p;
	else m->next=q;
	}
}
int main()
{
int x;
SLNode *la,*lb,*lc;
ListInitiate(&la);
ListInitiate(&lb);
ListInitiate(&lc);
int p,q,l;
for(p=0;p<10;p++)
{
		ListInsert(la, p, p+1);
		ListGet(la,p,&x);
	    printf("%d ",x);
	
}
printf("\n");
for(q=0;q<10;q++)
{
		ListInsert(lb, q, 2*q);
		ListGet(lb,q,&x);
	    printf("%d ",x);
}
int m;
Mergelist(la,lb,&lc);
printf("\n%d\n",ListLength(lc));
for(l=0;l<20;l++)
{
	ListGet(lc, l, &m); /*取元素*/
    printf("%d ", m);/*显示数据元素*/
	
}
}
