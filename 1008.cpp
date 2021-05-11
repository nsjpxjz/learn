#include<cstdio>
 
const int maxn=2000020;
 
int a[maxn];
 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        a[i]%=2;
    }
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=0;
        for(int i=l;i<=r;++i)
        {
            ans+=a[i];
        }
        ans%=2;
        printf("%d\n",ans);
    }
    return 0;
}