#include <stdio.h>
int judge(int a,int m,int n)
{
	int i,j;
	for (i=0;i*m<=a;i++)
	{
		for (j=0;j*n<=a;j++)
		{
			if (i*m+j*n==a) return 0;
		}
	} 
	return 1;
}
int main()
{
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	for (i=m*n; ;i--)
	{
		if (judge(i,m,n)) break;//若i能被m，n组合，则停止 
	}
	printf("%d",i);
	return 0;
}
