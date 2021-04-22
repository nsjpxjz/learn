#include <iostream>
#include<cstdio>
#define LL long long
const int mod=1e9+7;
using namespace std;
LL ans=1;
LL n,k,t;
int main()
{
    cin>>t;
    while(t--)
    {
        ans=1;
        cin>>n>>k;
        while(k--)
            ans=(ans*n)%mod;
            cout<<ans<<endl;
    }
    return 0;
}
