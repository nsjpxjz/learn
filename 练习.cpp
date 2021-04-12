#include <stdio.h>
#define N 20000
int main()
{
	int i,j,m,n,sum=0,k,flag,min=0;
    int A[N]={0};
    scanf("%d %d",&m,&n);//m为下界,n为上界 
    for (i=0;i<N;i++)
    {
    	A[i]=1;//1暂时标为幸运数 
	}
    for (i=2;i<=n;i++)//从2开始删 
    {
    	if (A[i]==0) continue;
    	else {
    	k=1;flag=0;
    	for (j=2;j<=n;j++)
    	{
    		if (A[j]==1) k++;//k标序 
    		if (A[j]==1&&k%i==0) A[j]=0;
		}
	    }
	}
	for (i=m+1;i<n;i++)
	{
		if (A[i]==1)
		{
		sum++;
		printf("%d ",i);
	    }
	}
	printf("%d",sum);
	return 0;
}
