#include <stdio.h>
int main()
{
	int m,n,i,j,k=0,num=0;
	scanf("%d %d",&m,&n);
	int A[m][n],B[m][n];
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
			B[i][j]=1;
		}
	}
	i=0;j=0;
	while (num!=m*n)
	{
	printf("%d ",A[i][j]);
	if ((i==m-1&&j==n-1)||(i==0&&j==n-1)||(i==m-1&&j==0))
	{
	k++;
	}
	switch (k%4)
	{
		case 0:i++;
		if (B[i+1][j]==0&&(i!=m-1||j!=0))
    	{
		k++;
    	}
		B[i-1][j]=0;break;
		case 1:j++;
		if (B[i][j+1]==0&&(i!=m-1||j!=n-1))
    	{
		k++;
    	}
		B[i][j-1]=0;break;
		case 2:i--;
		if (B[i-1][j]==0&&(i!=0||j!=n-1))
    	{
		k++;
    	}
		B[i+1][j]=0;break;
		case 3:j--;
		if (B[i][j-1]==0&&(i!=0||j!=0))
    	{
		k++;
    	}
		B[i][j+1]=0;break;
	}
	
	num++;
	}
	return 0;
}

