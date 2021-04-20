#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=2020;
const double eps=1e-9;

int n,t;

struct node
{
    double x,y,z;
};

node operator + (node a,node b)
{
    return node{a.x+b.x,a.y+b.y,a.z+b.z};
}

node operator - (node a,node b)
{
    return node{a.x-b.x,a.y-b.y,a.z-b.z};
}

node operator * (node a,node b)
{
    return node{a.y*b.z - a.z*b.y,a.z * b.x - a.x * b.z,a.x*b.y - a.y*b.x};
}

double operator ^ (node a,node b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double len(node x)
{
    return sqrt(x^x);
}

void ran(double &x)
{
    x=x+((double)rand()/(double)RAND_MAX-0.5)*eps*10;
}

node a[maxn];

struct man
{
    int v[3];
    node s()
    {
        return (a[v[1]]-a[v[0]])*(a[v[2]]-a[v[0]]);
    }
    bool view(node x)
    {
        return ((x-a[v[0]])^s())>0?true:false;
    }
};

void read()
{
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        node p;
        scanf("%lf%lf%lf",&p.x,&p.y,&p.z);
        bool flag=false;
        for(int j=1;j<=n;++j){
            if (fabs(p.x-a[j].x)<=eps&&fabs(p.y-a[j].y)<=eps&&fabs(p.z-a[j].z)<=eps)
            {
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            n++;
            a[n]=p;
        }
    }
    for(int i=1;i<=n;++i)
    {
        ran(a[i].x);
        ran(a[i].y);
        ran(a[i].z);
    }
}

bool vis[maxn][maxn];

double convex_hall()
{
    vector<man>x;
    x.push_back((man){1,2,3});
    x.push_back((man){3,2,1});
    for(int i=4;i<=n;++i)
    {
        vector<man>newx;
        for(int j=0;j<x.size();++j)
        {
            man f=x[j];
            bool r=f.view(a[i]);
            if(!r)newx.push_back(f);
            for(int k=0;k<3;k++)vis[f.v[k]][f.v[(k+1)%3]]=r;
        }
        for(int j=0;j<x.size();++j) {
            for (int k = 0;k <3; ++k){
                int a=x[j].v[k],b =x[j].v[(k+1)%3];
                if (vis[a][b]!=vis[b][a]&&vis[a][b])
                    newx.push_back((man){a, b, i});
            }
        }
        x=newx;
    }
    double ans=0;
    for(int i=0;i<x.size();++i)
    {
        ans+=len(x[i].s())/2;
    }
    return ans;
}

int main()
{
    read();
    printf("%.3lf",convex_hall());
    return 0;
}