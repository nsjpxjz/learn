#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,j;
    int A[10000]={0},B[10000]={0};//n阶乘的高精度算法 
    A[9999]=1;
    scanf("%d",&n);
	for (i=2;i<=n;i++)
	{
		for (j=9999;j>0;j--)
		{
			B[j]+=A[j]*i;
			if (B[j]>=10)
			{B[j-1]+=B[j]/10;B[j]%=10;}
		}
		for (j=0;j<10000;j++)
		{
			A[j]=B[j];
			B[j]=0;
		}
	} 
	for (i=0;A[i]==0;i++);
    for (;i<10000;i++)
    printf("%d",A[i]);
	return 0;
}
