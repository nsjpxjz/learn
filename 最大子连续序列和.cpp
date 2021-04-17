#include <stdio.h>
int main()
{
	int A[100000],i,n,sum,sum2;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	//对一个数组的最大子序列假设为A[i],A[i+1]...,A[m],A[i]必定＞0且对任意的k<i,A[k]+A[k+1]...+A[i-1]<0 
	sum=A[0];//sum存总的最大子序列和 
	sum2=0;//sum2存分子系列和 
	//从0开始加,若加到A[j](A[j]必为负数)时的sum2为负数,则此sum2为可能的最大子序列和,继续将sum2初始化为A[j+1]并继续循环 
	for (i=0;i<n;i++)
	{
		if (sum2>=0) sum2+=A[i];
		else sum2=A[i];
		if (sum<=sum2) sum=sum2;
	}
	printf("%d",sum);
	return 0;
}
