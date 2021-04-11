#include <iostream>
#include<cstring>
#include<cstdio>
const int MAX=505;
using namespace std;
int n,m,e,p[MAX],vis[MAX],map[MAX][MAX],ans;
bool match(int i)
{
    for(int j=1;j<=m;j++)
    {
        if(!vis[j]&&map[i][j])
        {
            vis[j]=1;
            if(!p[j]||match(p[j]))
            {
                p[j]=i;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>n>>m>>e;
    for(int i=1;i<=e;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b]=1;
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(match(i))
            ans++;
    }
    cout<<ans;
    return 0;
}
