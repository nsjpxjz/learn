#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#define maxn 200020
using namespace std;
int dfn[maxn],cur=0,low[maxn];
int n,m,head[maxn],col[maxn],ccnt,sta[maxn];
int top=0,tim=0,value[maxn],f[maxn],ans=0;
int zhi[maxn],x[maxn],y[maxn];
bool cut[maxn];
bool vis[maxn];
struct e
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    e ed={v,head[u]};
    edge[++cur]=ed;
    head[u]=cur;
}
void tarjan(int s,int r)
{
    int num=0;
    dfn[s]=low[s]=++tim;
    sta[++top]=s;
    vis[s]=true;
    for(int i=head[s],v=edge[i].to;i;i=edge[i].next,v=edge[i].to){
        if(!dfn[v]){
            tarjan(v,r);
            low[s]=min(low[s],low[v]);
            if((low[v]>=dfn[s])&&(s!=r)){
                cut[s]=1;
            }
            if(s==r){
                num++;
            }
        }
        else if(vis[v]){
            low[s]=min(low[s],dfn[v]);
        }
    }
    if(low[s]==dfn[s]){
        ++ccnt;
        vis[s]=false;
        while(sta[top+1]!=s){
            col[sta[top]]=ccnt;
            zhi[ccnt]+=value[sta[top]];
            vis[sta[top]]=false;
            top--;
        }
    }
    if((s==r)&&(num>=2)){
        cut[r]=1;
    }
}
int dfs(int x)
{
    if(f[x]){
        return f[x];
    }
    f[x]=zhi[x];
    int maxx=0;
    for(int i=head[x];i;i=edge[i].next){
        int to=edge[i].to;
        if(!f[to]){
            dfs(to);
        }
        maxx=max(f[to],maxx);
    }
    f[x]+=maxx;
    return f[x];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int mxx=0,sum=0;
        memset(cut,0,sizeof(cut));
        cur=top=tim=0;
        ans=0x3f3f3f3f;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&value[i]);
            mxx=max(value[i],mxx);
            sum+=value[i];
        }
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            x[i]=u;
            y[i]=v;
            add(u,v);
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i,i);
            }
        }
        memset(vis,false,sizeof(vis));
        memset(head,0,sizeof(head));
        memset(edge,0,sizeof(edge));
        cur=0;
        for(int i=1;i<=m;i++){
            if(col[x[i]]!=col[y[i]]){
                add(col[x[i]],col[y[i]]);
            }
        }
        for(int i=1;i<=ccnt;++i) {
            if (!f[i]) {
                dfs(i);
                ans = min(ans, f[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(cut[i]){
                ans++;
            }
        }
        printf("%d\n",sum-ans);
    }
    return 0;
}