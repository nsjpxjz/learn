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

}//���������������С�� 
int main()
{
	int i,j,k=0,n,max,min;//k���ڼ����������� 
	int A[50000];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for (i=2;i<=n;i++)//iΪ�����䳤�� 
	{
		for (j=0;j<=n-i;j++)
		{
			findmaxmin(A,j,j+i,&max,&min);
			if (max-min==i-1) k++;
		}
	}
	k+=n;//������һ������ 
	printf("%d",k);
	return 0;
}
