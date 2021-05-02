#include <stdio.h>/*���ļ�����printf()�Ⱥ���*/
#include <stdlib.h>/*���ļ�����exit()�Ⱥ���*/
#include <malloc.h>/*���ļ�����malloc()�Ⱥ���*/

typedef int DataType;/*����DataTypeΪint*/


typedef struct Node
{
	DataType data;
	struct Node *next;
} SLNode;

void ListInitiate(SLNode **head)/*��ʼ��*/
{
	/*������ڴ�ռ䣬����ͷ���ռ䲢ʹͷָ��headָ��ͷ���*/
	if((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
	(*head)->next = NULL;/*����β���NULL */
}

int ListLength(SLNode *head)               /* ������ĳ���*/
{
	SLNode *p = head;/*pָ����Ԫ���*/
	int size = 0;/*size��ʼΪ0*/
	
	while(p->next != NULL)/*ѭ������*/
	{
	p = p->next;
	size ++;
	}
	return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*�ڴ�ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size�����ǰ*/
/*����һ���������Ԫ��x�Ľ��*/
{
SLNode *p, *q;
int j;

p = head; /*pָ����Ԫ���*/
j = -1;/*j��ʼΪ-1*/
while(p->next != NULL && j < i - 1) 
/*������ָ��pָ������Ԫ��ai-1���*/
{
p = p->next;
j++;
}

if(j != i - 1)
{
printf("����λ�ò�����");
return 0;
}

/*�����½����ָ��qָʾ*/
if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
q->data = x;

//�˶γ�����һ������
q->next = p->next;/*��ָ��q->next��ֵ*/
p->next = q;/*��ָ��p->next���¸�ֵ*/
return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*ɾ����ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size - 1�����*/
/*ɾ����������Ԫ����ֵ��x���ء�ɾ���ɹ�ʱ����1��ʧ�ܷ���0*/
{
SLNode *p, *s;
int j;

p = head; /*pָ����Ԫ���*/
j = -1;/*j��ʼΪ-1*/
while(p->next != NULL && p->next->next!= NULL && j < i - 1) 
/*������ָ��pָ������Ԫ��ai-1���*/
{
p = p->next;
j++;
}

if(j != i - 1)
{
printf("ɾ��λ�ò�����");
return 0;
}

//�˶γ�����һ������
s=p->next; /*ָ��sָ������Ԫ��ai���*/
*x = s->data;/*��ָ��s��ָ��������Ԫ����ֵ����x*/
p->next = s->next;/*������Ԫ��ai���ӵ�������ɾ��*/
free(s);/*�ͷ�ָ��s��ָ�����ڴ�ռ�*/
return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*ȡ����Ԫ��ai��ɾ��������ͬ��ֻ�ǲ�ɾ������Ԫ��ai���*/
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
printf("ȡԪ��λ�ò�����");
return 0;
}

//�˶γ�����һ������
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
	ListGet(lc, l, &m); /*ȡԪ��*/
    printf("%d ", m);/*��ʾ����Ԫ��*/
	
}
}
