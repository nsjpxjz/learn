#include <stdio.h>
int findmaxmin(int A[],int a,int b,int *max,int *min)
{
	int i;
	*max=A[a],*min=A[a];
	for (i=a;i<b;i++)
	{
		if (*max<A[i]) *max=A[i];
		if (*min>A[i]) *min=A[i];
	}

}//区间里最大数和最小数 
int main()
{
	int i,j,k=0,n,max,min;//k用于计数连号区间 
	int A[50000];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for (i=2;i<=n;i++)//i为子区间长度 
	{
		for (j=0;j<=n-i;j++)
		{
			findmaxmin(A,j,j+i,&max,&min);
			if (max-min==i-1) k++;
		}
	}
	k+=n;//单曲间一定符合 
	printf("%d",k);
	return 0;
}
