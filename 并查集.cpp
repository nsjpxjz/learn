#include <iostream>
#include<cstdio>
const int MAX=10100;
using namespace std;
int n,m,p,q,as=1,bs=1,fa[MAX],fb[MAX],k=1;
int find(int x)
{
    if(k==1)
    if(fa[x]==x)
        return x;
    else return (fa[x]=find(fa[x]));
    else
    {
        if(fb[x]==x)
        return x;
    else return (fb[x]=find(fb[x]));
    }
}
void bing(int a,int b)
{
    if(k==1)
    {

    fa[find(a)]=find(b);
    }
    else
    {
        int fri=find(b);
        fb[find(a)]=fri;
    }


}

int main()
{
    cin>>n>>m>>p>>q;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        fb[i]=i;
    while(p--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        bing(a,b);
    }
    int ha=find(1);
    k=0;
    while(q--)
    {
        int a,b;
       scanf("%d%d",&a,&b);
       bing(-a,-b);
    }
    int hb=find(1);
    k=1;
    for(int i=2;i<=n;i++)
        if(find(i)==ha) as++;
    k=0;
    for(int i=2;i<=m;i++)
    if(find(i)==hb) bs++;
    cout<<min(as,bs);
    return 0;
}
