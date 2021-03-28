#include <stdio.h>
/*本题为dfs算法，自己不会写，看了csdn的源码之后才勉强看懂，copy下来了，
自己还没这水平写出来 */ 
int a[10][10];
int MinG=100;
int flag[10][10];
void dfs(int x,int y,int m,int n,int sum,int counts,int s)
{
	flag[x][y]=1;//防止原路返回 
	sum=sum+a[x][y];
	counts++;
	if(sum==s/2)
	{
		if(counts<MinG)
			MinG=counts;
	}
	else if(sum<s/2)//对每条能走的路都走一下，出口在s/2处 
	{
		if(x>=0&&x<n&&y-1>=0&&y-1<m&&flag[x][y-1]==0)//向上 
		{
			dfs(x,y-1,m,n,sum,counts,s);
			flag[x][y-1]=0;//回溯 
		}	
		if(x>=0&&x<n&&y+1>=0&&y+1<m&&flag[x][y+1]==0)//向下 
		{
			dfs(x,y+1,m,n,sum,counts,s);
			flag[x][y+1]=0;//回溯 
		}
		if(x-1>=0&&x-1<n&&y>=0&&y<m&&flag[x-1][y]==0)//向左 
		{
			dfs(x-1,y,m,n,sum,counts,s);
			flag[x-1][y]=0;//回溯 
		}
		if(x+1>=0&&x+1<n&&y>=0&&y<m&&flag[x+1][y]==0)//向右 
		{
			dfs(x+1,y,m,n,sum,counts,s);
			flag[x+1][y]=0;//回溯 
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
