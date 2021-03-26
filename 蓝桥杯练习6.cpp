#include <stdio.h>
#include <string.h>
int Num(char c);
int main()
{
	char A[10000];
	int C[40000];
	int B[10][10000];
	int i,j,n,len,k,u,a1,a2,a3,K[10];
	scanf("%d",&n);
	getchar();
	for (i=0;i<n;i++)
	{
		gets(A);
		for (j=0;j<40000;j++)//每次将C初始化 
		{
			C[j]='0';
		}
		len=strlen(A);
		for (j=0;j<len;j++)
		{
			k=Num(A[j]);//k为十进制 
			C[4*j+3]=k%2;
			C[4*j+2]=k/2%2;
			C[4*j+1]=k/2/2%2;
			C[4*j]=k/2/2/2%2;	
		}
		for (j=4*len-1,u=0;j>=0;j-=3,u++)
		{
			a1=C[j];
			if (j>=1) a2=C[j-1]*2;
			else a2=0;
			if (j>=2) a3=C[j-2]*4;
			else a3=0;//二进制抽离 
			B[i][u]=a1+a2+a3;	
		}
		K[i]=u-1;//八进制长度 
	}
	for (i=0;i<n;i++)
	{
		for (j=K[i]-1;j>=0;j--)
		{
			printf("%d",B[i][j]);
		} 
		printf("\n");
	}
	return 0;
}
int Num(char c)
{
	if (c>='0'&&c<='9') return c-'0';
	else return c-'A'+10;
}
