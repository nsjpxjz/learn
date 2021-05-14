#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Stack_Size 1000    
typedef struct{
    char Elem[Stack_Size];
    int top;
}Opter;
typedef struct{
    double Elem[Stack_Size];
    int top;
}Opnd;
void InitOpter(Opter *S){
    S->top=-1;
}
void InitOpnd(Opnd *S){
    S->top=-1;
}

int PopOpter(Opter *S)
{
    if(S->top==-1)
    {
        printf("运算符栈为空\n");
        exit(10);
    }
    S->top--;
    return 1;
}

int PopOpnd(Opnd *S)
{
    if(S->top==-1)
    {
        printf("运算符栈为空\n");
        exit(11);
    }
    S->top--;
    return 1;
}

int PushOpter(Opter* S,char ch)
{
    if(S->top==Stack_Size-1)
    {
        printf("运算符栈满\n");
        exit(12);
    }
    S->top++;
    S->Elem[S->top]=ch;
    return 1;
}

int PushOpnd(Opnd* S,double ch)
{
    if(S->top==Stack_Size-1)
    {
        printf("运算符栈满\n");
        exit(13);
    }
    S->top++;
    S->Elem[S->top]=ch;
    return 1;
}

char GetOpter(Opter *S)
{
    if(S->top==-1)
    {
        printf("运算符栈为空\n");
        exit(17);
    }
    return S->Elem[S->top];
}
double GetOpnd(Opnd *S)
{
    if(S->top==-1)
    {
        printf("操作数栈为空\n");
        exit(18);
    }
    return S->Elem[S->top];
}
double Calc(double a,double b,char opt)
{
    double T;
    if(opt=='+') T=a+b;
    if(opt=='-') T=a-b;
    if(opt=='*') T=a*b;
    if(opt=='/')
    {
        if(fabs(b)<0.00001)
        {
            printf("发生除0错误\n");
            exit(15);
        }
        T=a/b;
    }
    printf("中间过程输出：  %.0lf %c %.0lf = %.0lf\n",a,opt,b,T);
    return T;
}

int getIndex(char theta)
{
	int index = 0;
	switch (theta)
	{
	case '+':
	index =0;
	break;
	case'-':
	index=1;
	break;
	case'*':
	index=2;
	break;
	case'/':
	index=3;
	break;
	case'(':
	index=4;
	break;
	case')':
	index=5;
	break;
	case'#':
	index=6;
	default:break;
}
return index;
}
char getPriority(char theta1, char theta2)
{
const char priority[][7] = 
{ 
{ '>','>','<','<','<','>','>' }, 
{ '>','>','<','<','<','>','>' }, 
{ '>','>','>','>','<','>','>' }, 
{ '>','>','>','>','<','>','>' }, 
{ '<','<','<','<','<','=','0' }, 
{ '>','>','>','>','0','>','>' }, 
{ '<','<','<','<','<','0','=' }, 
};
int index1 = getIndex(theta1); 
int index2 = getIndex(theta2);
return priority[index1][index2];
}
int Compare(char ch1,char ch2)
{
    if(!getPriority(ch1,ch2)){
        printf("输入表达式错误");
        exit(0);
    }
    return getPriority(ch1,ch2);
}
int main()
{
    char a[1000],b[1000];         
    int len;        
    Opter S;    
    Opnd N;    
    InitOpnd(&N);   
    InitOpter(&S);   
    PushOpter(&S,'#');  
    printf("输入表达式：\n");
    scanf("%s",a);    
    len=strlen(a);   
    int i,j=0,k=0;
    double x,y;  
    a[len]='#';  
    for(i=0;i<=len;i++)
    {
        if((a[i]>='0'&&a[i]<='9')||a[i]=='.')
        {
            b[k++]=a[i];
            j=1;
            continue;  
        }
        if(j)
        {
            b[k]='\0';
            PushOpnd(&N,atof(b));
            j=0;
            k=0;  
        }
        switch(Compare(GetOpter(&S),a[i]))
        { 
     
        case '<':
            PushOpter(&S,a[i]);
            break;
        case'=':
            PopOpter(&S);
            break;
        case'>':
            y=GetOpnd(&N),PopOpnd(&N);
            x=GetOpnd(&N),PopOpnd(&N);
            PushOpnd(&N,Calc(x,y,GetOpter(&S)));
            PopOpter(&S);
            
            i--;
            break;
        }
    }
    double answer=GetOpnd(&N);
        printf("最终结果为%.0lf",answer);
        return 0;
}

