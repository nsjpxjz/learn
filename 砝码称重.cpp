#include <stdio.h>
int fib(int n)
{
	return n>0?n:-n;
}
int judge(int B[],int n,int k)
{
	int i;
	for (i=0;i<n;i++)
	{
		if (B[i]==k) return 0;
	}
	return 1;
}
int main()
{
	int A[10000],B[10000];
	int i,j,n,q=1,k;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	B[0]=A[0];
	for (i=1;i<n;i++)
	{
		k=q;
		for (j=0;j<k;j++)
		{
			B[q]=B[j]+A[i];
			if (judge(B,q,B[q])) q++;
		}
		for (j=0;j<k;j++)
		{
			B[q]=fib(B[j]-A[i]);
			if (judge(B,q,B[q])) q++;
		}
		B[q]=A[i];
		if (judge(B,q,B[q])) q++;
	}
	for (j=0;j<q;j++)
	{
		printf("%d ",B[j]);
	}
	printf("%d",q);
	return 0;
}
