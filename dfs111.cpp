#include <iostream>
const int MAX=202000;
using namespace std;
long long ans,nasn,d[MAX],n,dx,dy;
void dfs(int x ,int y)
{
    if(dx==dy)
        ans=dx;
    if(x>y)
    {
        return;
    }
        if(dx>=dy)
        {
            dy+=d[y];
            dfs(x,y-1);
        }
        else
        {
            dx+=d[x];
            dfs(x+1,y);
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>d[i];
        dfs(1,n);
    cout<<ans;
    return 0;
}
