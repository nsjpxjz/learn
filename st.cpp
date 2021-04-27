#include <bits/stdc++.h>
const int MAX=50005;
using namespace std;
int lo[MAX],Min[MAX][17],Max[MAX][17],n,q;
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        Max[i][0]=Min[i][0]=x;
    }
    for(int i=2;i<=n;i++)
        lo[i]=lo[i/2]+1;
    for(int i=1;i<=16;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
    {
        Min[j][i]=min(Min[j][i-1],Min[j+(1<<(i-1))][i-1]);
        Max[j][i]=max(Max[j][i-1],Max[j+(1<<(i-1))][i-1]);
    }
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        int s=lo[b-a+1];
        int ma=max(Max[a][s],Max[b-(1<<s)+1][s]);
        int mi=min(Min[a][s],Min[b-(1<<s)+1][s]);
        printf("%d\n",ma-mi);
    }
    return 0;
}
