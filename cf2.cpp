#include <iostream>
#include<cstdio>
#include<map>
#include<cstring>
const int MAX=202000;
const int mod=1e9+7;
using namespace std;
long long  t,n,m;
long long  q[202000];
long long df(int k)
{
    if(k<10)
        return 1;
    else if(k==10)
        return 2;
    else
    {
        return (q[k-9]+q[k-10])%mod;
    }

}
int main()
{
    cin>>t;
    for(int i=1; i<=9; i++)
            q[i]=1;
    for(int i=10; i<MAX; i++)
            q[i]=df(i);
    while(t--)
    {
        long long ans=0;
        scanf("%lld %lld",&n,&m);
        while(n/10)
        {
            ans+=q[n%10+m];
            ans%=mod;
            n/=10;
        }
        ans+=q[n+m];
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
