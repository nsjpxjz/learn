#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,fa[2020],rank[2020],ans;
int find (int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void add(int a,int b)
{
    int x=find(a),y=find(b);
    if(rank[x]>=rank[y])
        fa[y]=x;
    else fa[x]=y;
    if(rank[x]==rank[y])
        rank[x]++;
}
int main()
{
    cin>>n;
    cin>>m;
    for(int i=1; i<=2*n; i++)
    {
        fa[i]=i;
        rank[i]=1;
    }

    for(int i=1; i<=m; i++)
    {
        int a,b;
        char c;
        cin>>c>>a>>b;
        if(c=='F')
        {
            add(a,b);
        }
        else if(c=='E')
        {
            add(a,b+n);
            add(b,a+n);
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(fa[i]==i)
            ans++;
    }
    cout<<ans;
    return 0;
}
