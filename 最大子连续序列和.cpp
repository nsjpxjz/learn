#include <stdio.h>
int main()
{
	int A[100000],i,n,sum,sum2;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	//��һ���������������м���ΪA[i],A[i+1]...,A[m],A[i]�ض���0�Ҷ������k<i,A[k]+A[k+1]...+A[i-1]<0 
	sum=A[0];//sum���ܵ���������к� 
	sum2=0;//sum2�����ϵ�к� 
	//��0��ʼ��,���ӵ�A[j](A[j]��Ϊ����)ʱ��sum2Ϊ����,���sum2Ϊ���ܵ���������к�,������sum2��ʼ��ΪA[j+1]������ѭ�� 
	for (i=0;i<n;i++)
	{
		if (sum2>=0) sum2+=A[i];
		else sum2=A[i];
		if (sum<=sum2) sum=sum2;
	}
	printf("%d",sum);
	return 0;
}
