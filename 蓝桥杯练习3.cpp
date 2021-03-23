#include <stdio.h>
#include <string.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	char A[100],B[100];//将读进的大数存进字符串 
	int C[100]={0},D[100]={0},E[100]={0},i,j,n1,n2;
	gets(A);
	gets(B);
	n1=strlen(A);
	n2=strlen(B);
	for (i=100-n1,j=0;i<=99;i++,j++)
	{
		C[i]=A[j]-'0';
	}
	for (i=100-n2,j=0;i<=99;i++,j++)
	{
		D[i]=B[j]-'0';
	}//字符串转数字并排位 
	for (i=99;i>=100-max(n1,n2);i--)
	{
		E[i]+=D[i]+C[i];
		if (E[i]>=10) 
		{
			E[i]-=10;
			E[i-1]+=1;
		}
	}
	for (i=0;E[i]==0;i++);
    for (;i<100;i++)
    printf("%d",E[i]);
	return 0;
}
