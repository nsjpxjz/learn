#include<cstdio>
#define ll long long
#define mod 1000000007
 
ll a,b,c;
 
int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    ll ans;
    ans=(a%mod)*(b%mod)%mod;
    ans*=(c%mod);
    ans%=mod;
    printf("%lld\n",ans);
    return 0;
}