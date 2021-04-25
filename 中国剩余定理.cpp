#include<bits/stdc++.h>
#define  LL long long
using namespace std;
LL gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL d=gcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
inline LL inv (LL a,LL b)
{
    LL x,y;
    gcd(a,b,x,y);
    return (x%b+b)%b;
}
inline LL crt(LL *a,LL *b,LL n)
{
    LL p=1,x=0;
    for(int i=1;i<=n;i++)
        p*=a[i];
    for(int i=1;i<=n;i++)
    {
        LL r=p/a[i];
        x+=(b[i]*r*inv(r,a[i]))%p;
    }
    return x%p;
}
int main()
{
    LL n,a[11],b[11];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    cout<<crt(a,b,n);
    return 0;
}
