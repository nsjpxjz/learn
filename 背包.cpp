#include <iostream>
#include<cstdio>
const int MAX=1010000;
using namespace std;
typedef long long LL;
int n,x,l[MAX],u[MAX],w[MAX];
LL k[1010];
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&l[i],&w[i],&u[i]);
        for(int j=x;j>=0;j--)
                k[j]+=l[i];
        for(int j=x;j>=u[i];j--)
        {

            k[j]=max(k[j-u[i]]+w[i]-l[i],k[j]);

        }

    }
    cout<<k[x]*5;
    return 0;
}
