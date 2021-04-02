#include <iostream>

using namespace std;
int n,m,k[110][110],a[110];
int main()
{
    cin>>n>>m;
    k[0][0]=1;
    for(int i=1;i<=n;i++)
        cin>>a[i],k[i][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
        {
            for(int t=0;t<=a[i]&&t<=j;t++)
                k[i][j]+=k[i-1][j-t];
            k[i][j]%=1000007;
        }
        cout<<k[n][m];
    return 0;
}
