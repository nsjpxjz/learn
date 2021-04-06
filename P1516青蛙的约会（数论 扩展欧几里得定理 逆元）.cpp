#include<cstdio>
#define ll long long

ll ans,xx,yy,n,m,x,y,l;

ll exgcd(ll a,ll b,ll &xx, ll &yy)
{
    if(!b)
    {
        xx=1,yy=0;
        return a;
    }
    ans=exgcd(b,a%b,xx,yy);
    ll t=xx;
    xx=yy,yy=t-a/b*yy;
    return ans;
}

int main()
{
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    ll b=n-m,a=x-y;
    if(b<0)b=-b,a=-a;
    exgcd(b,l,xx,yy);
    if(a%ans!=0)puts("Impossible");
    else printf("%d",((xx*(a/ans))%(l/ans)+(l/ans))%(l/ans));
}