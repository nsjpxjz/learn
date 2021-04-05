#include <iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL a,c,b;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
int main()
{
    LL x,y,t;
    cin>>a>>b>>c;
    t=exgcd(a,b,x,y);
    if(c%t)
    {
       printf("-1");
       return 0;
    }
    x=-c/t*x;
    y=-c/t*y;
    cout<<x<<' '<<y;
    return 0;
}
