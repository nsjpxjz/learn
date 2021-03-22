#include <iostream>

using namespace std;
int n,m,a,b,map[25][25],dx[8]= {1,1,-1,-1,2,2,-2,-2},dy[8]= {2,-2,2,-2,1,-1,1,-1};
long long k[25][25];
int main()
{
    cin>>n>>m>>a>>b;
    map[a][b]=-1;
    for(int p=0; p<8; p++)
        if(a+dx[p]>=0&&b+dy[p]>=0)
        {
            map[a+dx[p]][b+dy[p]]=-1;
        }
    for(int i=0; i<=n; i++)
    {

        if(map[i][0]==-1)
            break;
        else
            k[i][0]=1;
    }
    for(int j=0; j<=m; j++)
    {
        if(map[0][j]==-1)
            break;
        else
            k[0][j]=1;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(map[i][j]==-1)
                k[i][j]=0;
            else
                k[i][j]=k[i-1][j]+k[i][j-1];
        }
    cout<<k[n][m];
    return 0;
}
