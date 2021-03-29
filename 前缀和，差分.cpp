#include <iostream>
#include<cstdio>
#define LL long long
const int MAX=101000;
using namespace std;
int n,m,a[MAX],b[MAX],c[MAX],p[MAX],t;
long long ans,k[MAX],di[MAX];
int main()
{
    cin>>n>>m;
    scanf("%d",&p[1]);
    t=p[1];
    for(int i=2; i<=m; i++)
    {
        scanf("%d",&p[i]);
        if(p[i]>t)
           di[t]++,di[p[i]]--;
        else
            di[p[i]]++,di[t]--;
        t=p[i];
    }
    for(int i=1;i<n;i++)
        k[i]=di[i]+k[i-1];
    for(int i=1; i<n; i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        if((LL)(c[i]+(LL)(k[i]*b[i]))<=(LL)(k[i]*a[i]))
            ans+=(LL)(c[i]+(LL)(k[i]*b[i]));
        else ans+=(LL)(k[i]*a[i]);
    }
    cout<<ans;
    return 0;
}
