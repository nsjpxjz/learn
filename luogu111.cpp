#include <iostream>
#include<algorithm>
using namespace std;
int n,vis[110],fa[110],rank[110];
struct node
{
    int aa,bb,w;
}a[10000];
long long ans;
int find(int x)
{
    return x==fa[x]?x:(fa[x]=find(fa[x]));
}
inline void add(int a,int b)
{
    int x=find(a),y=find(b);
    if(rank[x]>=rank[y])
        fa[y]=x;
    else fa[x]=y;
    if(rank[x]==rank[y]&&x!=y)
        rank[x]++;
}
bool cmp(node a,node b)
{
    return a.w<b.w;
}
bool cf(int a,int b)
{
    return find(a)==find(b);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        rank[i]=1;
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            int t;
            cin>>t;
            if(i>j)
            {
                a[++cnt].aa=i;
                a[cnt].bb=j;
                a[cnt].w=t;
            }
        }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int aaa=a[i].aa,bbb=a[i].bb;
        if(!cf(aaa,bbb))
        {
            ans+=a[i].w;
            add(aaa,bbb);
        }
    }
    cout<<ans;
    return 0;
}
