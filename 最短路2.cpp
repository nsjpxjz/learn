#include <iostream>
#include<queue>
#include<cstdio>
#include<vector>
const int MAX=202000;
const int M=101000;
const int INF=2046789348;
using namespace std;
struct edge
{
    int to,w,next;
}edge[MAX];
int vis[M],head[M],n,m,s,dist[M],cnt;
struct par
{
    int dist,id;
    par(int dist,int id) : dist(dist),id(id){};
};
struct cmp
{
    bool operator()(par a,par b)
    {
        return a.dist>b.dist;
    }
};
priority_queue<par,vector<par>,cmp>q;
inline void add(int a,int b,int c)
{
    edge[++cnt].to=b;
    edge[cnt].w=c;
    edge[cnt].next=head[a];
    head[a]=cnt;
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
        dist[i]=INF;
    dist[s]=0;
    for(int i=1;i<=m;i++)
    {
        int v,u,w;
        scanf("%d %d %d",&v,&u,&w);
        add(v,u,w);
    }
    q.push(par(0,s));
    while(!q.empty())
    {
        int p=q.top().id;
        q.pop();
        if(vis[p])
            continue;
        vis[p]=1;
        for(int e=head[p];e;e=edge[e].next)
        {
            int to=edge[e].to;
            dist[to]=min(dist[to],dist[p]+edge[e].w);
                if(!vis[to])
                    q.push(par(dist[to],to));
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF)
            cout<<(1<<31)-1<<' ';
        else
            printf("%d ",dist[i]);
    }
    return 0;
}
