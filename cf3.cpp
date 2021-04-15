#include <iostream>
#include<cstdio>
#include<cstring>
#define LL long long
const int MAX=202000;
const int mod=1e9+7;
using namespace std;
LL t,n,a[MAX],ap[MAX];
LL cf()
{
    LL ans=a[1];
    for(int i=2; i<=n; i++)
        ans=ans&a[i];
    return ans;
}
int main()
{
    cin>>t;
    ap[0]=1;
    for(int i=1; i<=MAX; i++)
        ap[i]=ap[i-1]*i%mod;
    while(t--)
    {
        scanf("%lld",&n);
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
            scanf("%lld",&a[i]);
        int kp=cf(),k=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i]==kp)
                k++;
        }
        if(k<2)
        {
            printf("0\n");
            continue;
        }
        else
        {
            printf("%lld\n",(ap[n-2]*k%mod)*(k-1)%mod);
        }
    }
    return 0;
}
