#include <stdio.h>
int sum=0;
void find(int step,int n)//step为当前步数,n为当前阶梯 
{
	if (n==39&&step%2==0) 
	{
		sum++;
	}
	else if (n<39)
	{
	find(step+1,n+1);
	find(step+1,n+2);
    }
}
int main()
{
	find(0,0);//从阶梯0,步数0起步 
    printf("%d",sum);
    return 0;
}

