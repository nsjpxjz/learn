#include <stdio.h>
/*����Ϊdfs�㷨���Լ�����д������csdn��Դ��֮�����ǿ������copy�����ˣ�
�Լ���û��ˮƽд���� */ 
int a[10][10];
int MinG=100;
int flag[10][10];
void dfs(int x,int y,int m,int n,int sum,int counts,int s)
{
	flag[x][y]=1;//��ֹԭ·���� 
	sum=sum+a[x][y];
	counts++;
	if(sum==s/2)
	{
		if(counts<MinG)
			MinG=counts;
	}
	else if(sum<s/2)//��ÿ�����ߵ�·����һ�£�������s/2�� 
	{
		if(x>=0&&x<n&&y-1>=0&&y-1<m&&flag[x][y-1]==0)//���� 
		{
			dfs(x,y-1,m,n,sum,counts,s);
			flag[x][y-1]=0;//���� 
		}	
		if(x>=0&&x<n&&y+1>=0&&y+1<m&&flag[x][y+1]==0)//���� 
		{
			dfs(x,y+1,m,n,sum,counts,s);
			flag[x][y+1]=0;//���� 
		}
		if(x-1>=0&&x-1<n&&y>=0&&y<m&&flag[x-1][y]==0)//���� 
		{
			dfs(x-1,y,m,n,sum,counts,s);
			flag[x-1][y]=0;//���� 
		}
		if(x+1>=0&&x+1<n&&y>=0&&y<m&&flag[x+1][y]==0)//���� 
		{
			dfs(x+1,y,m,n,sum,counts,s);
			flag[x+1][y]=0;//���� 
		}	
	}
}
int main()
{
	int m,n,i,j;
	scanf("%d%d",&m,&n);
	int s=0;
	int flag[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			s=s+a[i][j];
		}	
	}
	dfs(0,0,m,n,0,0,s);
	if(MinG<100)
		printf("%d",MinG);
	else printf("0");
	return 0;
} 
