#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>

int n,m,ans=0;
double E;

struct Edge{
    int next,to;
    double w;
}fe[2000010],e[2000010];
int head[2000010]={0},cnt=1,dehead[2000010]={0},decnt=1;
void add(int u,int v,double w)
{
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;

    fe[decnt].to=u;
    fe[decnt].w=w;
    fe[decnt].next=dehead[v];
    dehead[v]=decnt++;
}

double dis[500010];
bool inq[500010]={true};
void spfa()
{
    memset(dis,0x7f,sizeof(dis));
    dis[n]=0.0;
    std::queue<int> q;
    q.push(n);
    inq[n]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=dehead[u];i;i=fe[i].next)
        {
            int v=fe[i].to;
            double w=fe[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!inq[v])
                {
                    inq[v]=true;
                    q.push(v);
                }
            }
        }
    }
}
struct Heap{
    double d;
    int u;
    bool operator > (const Heap &a)const{
        return d>a.d;
    }
}heap[2000010];
int sz=1;
void pop()
{
    sz--;
    heap[1]=heap[sz];
    heap[sz]={0,0};
    int the=1,son=2;
    while(son<sz)
    {
        if(heap[son]>heap[son+1]&&son+1<sz) son++;
        if(heap[the]>heap[son]) std::swap(heap[the],heap[son]);
        else break;
        the=son;
        son=the<<1;
    }
}
void push(double dd,int uu)
{
    heap[sz]={dd,uu};
    int the=sz++,fa=the>>1;
    while(fa)
    {
        if(heap[fa]>heap[the]) std::swap(heap[the],heap[fa]);
        else break;
        the=fa;
        fa>>=1;
    }
}

void astar()
{
    push(dis[1],1);
    while(sz>1)
    {
        int u=heap[1].u;
        double dist=heap[1].d;
        pop();
        if(u==n)
        {
            E-=dist;
            if(E>=1e-6) ans++;
            else return;
            continue;
        }
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            double w=e[i].w;
            push(dist-dis[u]+w+dis[v],v);
        }
    }
}

int main()
{
    std::cin>>n>>m>>E;
    for(int i=1,u,v;i<=m;i++)
    {
        double w;
        std::cin>>u>>v>>w;
        add(u,v,w);
    }
    spfa();
    astar();
    printf("%d\n",ans);
    return 0;
}
