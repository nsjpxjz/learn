#include <stdio.h>
int cut(int A[],int n)//删除数组中最小元素并返回 
{
	int i,j,min,k=0;
	min=A[0];
	for (i=1;i<n;i++)
	{
		if (min>A[i]) 
		{
			min=A[i];
			k=i;
		}
	}
	for (i=k;i<n-1;i++)
	{
		A[i]=A[i+1];
	}
	return min;
}
int main()
{
	int n,i,j,min,min2,sum=0;
	scanf("%d",&n);	
	int A[n];
	for (i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for (i=n;i>1;i--)
	{
		min=cut(A,i);
		min2=cut(A,i-1);
		A[i-2]=min+min2;
		sum+=min+min2;
	}
	printf("%d",sum);
    return 0;
}
