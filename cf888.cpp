#include<bits/stdc++.h>
#include<iostream>
#define LL long long
const LL MA=(2050*(1e14));
using namespace std;
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        LL n;
        LL ans=0;
        LL k=MA;
        cin>>n;
        while(1)
        {
            while(!(n/k)&&n)
            {
                k/=10;
            }
            if(k<2050)
                break;
            if(n/k)
            {
                LL p=n/k;
                ans+=p;
                n%=k;
            }
            if(n==0)
                break;
        }
        if(n)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
