#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n,flag[1000]={0},sum=0;
	char A[1000],B[1000];
	gets(A);
	gets(B);
	n=strlen(A);
    for (i=0;i<n;i++)
    {
    	if (A[i]!=B[i]) flag[i]=1;//����Ϊ����ͬ��תΪ��ͬ�� 
	}
	for (i=0;i<n;i++)
	{
		if (flag[i]==1)
		{
			for (j=i+1;j<n;j++)
			{
				if (flag[j]==1) break;
			}//�ҵ���һ��ҲΪ1��Ԫ��
			sum+=j-i; 
		}
		i=j;
	}
	printf("%d",sum);
	return 0;
}
