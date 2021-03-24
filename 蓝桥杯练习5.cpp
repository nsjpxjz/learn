#include <stdio.h> 
void Swap(double *p1,double *p2)
{
	double k;
	k=*p1;
	*p1=*p2;
	*p2=k;
}
double max(double a,double b)
{
	return a>b?a:b;
}
double min(double a,double b)
{
	return a>b?b:a;
}
int get(double a,double b,double c,double d)//a,b为前两个坐标横坐标，c，d为后两个坐标横坐标 
{
	if (c<min(a,b)&&d<min(a,b)||c>max(a,b)&&d>max(a,b))
	return 0;
	else return 1;
}//判断区间是否有交集 
double area(double a,double b,double c,double d)//返回交集长度 
{
	double B[4]={a,b,c,d};
	int i,j;
	for (i=0;i<4;i++)
	{
		for (j=0;j<4-i-1;j++)
		{
			if (B[j]>B[j+1])
			{
				Swap(&B[j],&B[j+1]);
			}
		}
	}
	return B[2]-B[1];
}
int main()
{
    double a1,a2,b1,b2,c1,c2,d1,d2;
    double S;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2);
    if (get(a1,b1,c1,d1)&&get(a2,b2,c2,d2)) 
    S=area(a1,b1,c1,d1)*area(a2,b2,c2,d2);
    else S=0;
    printf("%.2f",S);
	return 0;
} 
