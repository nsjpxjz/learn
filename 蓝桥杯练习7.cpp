#include <stdio.h>
int main()
{
	int N,i,j,min,k,q,n,l,f,target1,target2,temp;
	char A[100][1000];
	int B[100]={0};
	scanf("%d",&N);
	getchar();
	for (i=0;i<N;i++)
	{
		gets(A[i]);
	}
	for (i=0;i<10;i++)
	{
		for (j=0;j<1000;j++)
		{
			if (A[i][j]==' ') continue;
			if (A[i][j]=='\0') {j=0;break;}
			else{
				for (k=j;A[i][k+1]!=' '&&A[i][k+1]!='\0';k++);//kΪ���һ�������±� 
			    for (q=k;q>=j;q--)
				{
				l=k-q;//lΪ��Ҫ��10�ĸ��� 
				f=A[i][q]-'0';
				while (l>0) {f*=10;l--;}
				B[n]+=f; 
	            }
	            j=k;
				n++;
	        }   
		} 
	}
	for (n=0;B[n]!=0;n++);//nΪ���� 
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (B[i]==B[j]) {target1=B[i];break;}//���� 
	    }
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-1-i;j++)
		{
		if (B[j]>B[j+1])
		{
			temp=B[j];
			B[j]=B[j+1];
			B[j+1]=temp;
		}
		}
	}//���� 
	for (i=0;i<n-1;i++)
	{
		if (B[i+1]-B[i]==2) target2=B[i]+1;//��© 
	}
	printf("%d %d",target2,target1);
	return 0;
}
