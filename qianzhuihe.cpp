#include <iostream>
#include<cstdio>
#include<algorithm>
const int MAX=202000;
using namespace std;
int a,s[MAX],n,ans;
int main()
{
    cin>>n>>a;
    ans=a;
    s[1]=a;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a);
        s[i]=s[i-1]+a;
        if(s[i]>ans) ans=s[i];
        if(s[i]<0)
        {
           s[i]=a;
           if(ans<a) ans=a;
        }
    }

    cout<<ans;
    return 0;
}
