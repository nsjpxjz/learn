#include <stdio.h>
long long f(long long a,long long n)//aΪ����,nΪ���� 
{
	return (a+a+n-1)*n/2;//�Ȳ�������� 
}
int main()
{
	long long n,i,j,k,T,sum=1,q=0;
	long long B[1000000];
	B[1]=1;//��1��ʼ 
	scanf("%lld %lld %lld",&n,&k,&T);//nΪ����,kΪ����,TΪ����
	for (i=n+1,q=2;i<T*n+1;i+=n,q++)
	{
	    B[q]=B[q-1]+f(i-n,n);
	    B[q]%=k;
		sum+=B[q];
	} 
	printf("%lld",sum);
	return 0;
}
