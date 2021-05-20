#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include "cstring"
using namespace std;
int main()
{
    int dp[101000],cnt=1,len=0,a[101000];
    while(cin>>a[cnt]){cnt++;}
    dp[0]=6000000;
    for(int i=1;i<cnt;i++)
    {
        if(dp[len]>=a[i])
            dp[++len]=a[i];
        else *upper_bound(dp+1,dp+len+1,a[i],greater<int>() )=a[i];
    }
    cout<<len<<endl;
    len=0;
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<cnt;i++)
    {
        if(dp[len]<a[i])
            dp[++len]=a[i];
        else *lower_bound(dp+1,dp+1+len,a[i])=a[i];
    }
    cout<<len<<endl;
    return 0;
}