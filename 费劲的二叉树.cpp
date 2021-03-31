#include <iostream>
#include<queue>
#include<cstdio>
#include<cmath>
const int MAX=202000;
using namespace std;
int n;
char c;
bool vis[MAX];
struct node
{
    int ne,pr,t,bo;
} nu[MAX];
struct kh
{
    int a,b;
} op[MAX];
struct ch
{
    int a,b,cha;

} yo;

bool operator <( ch a, ch b)
{
    if(a.cha==b.cha)
        return a.a>b.a;
    return a.cha>b.cha;
}
priority_queue<ch ,vector<ch> >q;

int main()
{
    cin>>n;
    getchar();
    for(int i=1; i<=n; i++)
    {
        scanf("%c",&c);
        if(c=='B')
            nu[i].bo=1;
        else nu[i].bo=2;
        nu[i].pr=i-1;
        nu[i].ne=i+1;
    }
    getchar();
    for(int i=1; i<=n; i++)
        scanf("%d",&nu[i].t);
    for(int i=1; i<n; i++)
    {
        if(nu[i].bo!=nu[i+1].bo)
        {
            yo.a=i;
            yo.b=i+1;
            yo.cha=abs(nu[i].t-nu[i+1].t);
            q.push(yo);
        }
    }
    int l=0;
    ch g;
    if(q.empty())
    {
        cout<<'0';
        return 0;
    }
    while(!q.empty())
    {
        g=q.top();
        if(vis[g.a]==1||vis[g.b]==1)
        {
               q.pop();
            continue;
        }
        op[++l].a=g.a;
        op[l].b=g.b;
           q.pop();
        vis[g.a]=vis[g.b]=1;
        int ai=g.a,bi=g.b;
        int bn=nu[bi].ne,ar=nu[ai].pr;
        nu[bn].pr=nu[ai].pr;
        nu[ar].ne=nu[bi].ne;
        if(ar>=1&&bn<=n&&nu[bn].bo!=nu[ar].bo)
        {
            yo.a=ar;
            yo.b=bn;
            yo.cha=abs(nu[ar].t-nu[bn].t);
            q.push(yo);
        }
    }
    cout<<l<<endl;
    for(int i=1;i<=l;i++)
        printf("%d %d\n",op[i].a,op[i].b);
    return 0;

}
