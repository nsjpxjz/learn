#include <stdio.h>
int sum=0;
void find(int step,int n)//stepΪ��ǰ����,nΪ��ǰ���� 
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
	find(0,0);//�ӽ���0,����0�� 
    printf("%d",sum);
    return 0;
}

