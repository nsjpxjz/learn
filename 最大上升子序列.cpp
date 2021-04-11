#include<bits/stdc++.h>
using namespace std;
int n,t[110],k[110],ans;
int fa(int x)
{
    int dpl[110];
    int dp[110],kp=0,kpl=0;
    memset(dp,0,sizeof(dp));
    memset(dpl,0,sizeof(dpl));
    for(int i=1;i<x;i++)
    {
        if(t[i]>=t[x])
            continue;
        if(dp[kp]<t[i])
        dp[++kp]=t[i];
        else
            *lower_bound(dp+1,dp+kp+1,t[i])=t[i];
    }
    for(int i=x+1;i<=n;i++)
    {
        if(t[i]>=t[x])
            continue;
            if(i==x+1)
            {
                dpl[1]=t[i];
                kpl++;
                continue;
    }
        if(dpl[kpl]>t[i])
            dpl[++kpl]=t[i];
        else
            *lower_bound(dpl+1,dpl+1+kpl,t[i],greater<int>())=t[i];
    }
    return kp+kpl+1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,fa(i));
    }
    cout<<n-ans;
    return 0;
}
