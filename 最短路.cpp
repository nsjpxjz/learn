#include <iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<vector>
const int INF=2035469855;
using namespace std;
int n,m,s,vis[10100],dist[10100];
struct edge
{
    int to,w,next;

}ed[505000];
int head[10100],cnt;
queue<int>q;
inline void add(int f,int t,int w)
{
    ed[++cnt].w=w;
    ed[cnt].to=t;
    ed[cnt].next=head[f];
    head[f]=cnt;
}
int main()
{
   cin>>n>>m>>s;
   for(int i=1;i<=m;i++)
   {
       int a,b,c;
       scanf("%d %d %d",&a,&b,&c);
       add(a,b,c);
   }

  for(int i=1;i<10100;i++)
    dist[i]=INF;
   dist[s]=0;
   q.push(s);
   while(!q.empty())
   {
        int p=q.front();
        q.pop();
        vis[p]=0;
        for(int i=head[p];i!=0;i=ed[i].next)
        {
            int to=ed[i].to;
            if(dist[to]>dist[p]+ed[i].w)
            {
                dist[to]=dist[p]+ed[i].w;
                if(!vis[to])
                {
                    vis[to]=1;
                    q.push(to);
                }
            }
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
