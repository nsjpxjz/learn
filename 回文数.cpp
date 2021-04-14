#include <stdio.h>
int judge(int n)
{
	int i1=0,i2=0,j=0,sum=0;
	int A[10];
	while (n>0)
	{
		A[j]=n%10;
		n/=10;
		j++;
	}
	for (i1=0,i2=j-1;i1<i2;i1++,i2--)
	{
		if (A[i1]!=A[i2]) return 0;
	}
	for (i1=0;i1<j;i1++)
	{
		sum+=A[i1];
	}
	return sum;
}
int main()
{
	int n,i,flag=0;
	scanf("%d",&n);
	for (i=10000;i<1000000;i++)
	{
		if (judge(i)==n) { printf("%d\n",i);flag=1;}
	}
	if (!flag) printf("-1");
	return 0;
}
