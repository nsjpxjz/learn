#include<cstdio>

int a,b;

void swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}

int main()
{
    while(~scanf("%d%d",&a,&b)&&a&&b) {
        int cnt = 1;
        if(a<b)swap(a,b);
        while(a%b && a/b==1)
        {
            a-=b;
            if(a<b)swap(a,b);
            cnt^=1;
        }
        if(!cnt)puts("Ollie wins");
        else puts("Stan wins");
    }
    return 0;
}