#include <bits/stdc++.h>
const int MAX=202000;
using namespace std;
vector<int>ou[MAX],in[MAX];
map<int,int>t[MAX];
int n,vis[MAX],d[MAX],h[MAX],k[MAX],s[MAX];
void dfs(int x)
{

}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        ou[a].push_back(b);
        in[b].push_back(a);
        k[a]++;
        t[a][b]=i;
        s[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(k[i]==0)
            dfs(i);
    }
    return 0;
}
