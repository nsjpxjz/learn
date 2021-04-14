#include <iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
const int MAX=303000;
using namespace std;
int n,q,a[MAX],k[MAX],po[MAX],df=1;
struct node
{
    int num,l,r;
}qw[MAX];
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&qw[i].num);
        qw[i].r=i+1;
        qw[i].l=i-1;
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&k[i]);
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=df,h=1;j<=n&&h<=n;h++)
        {
            int x=qw[j].l,y=qw[j].r;
            if(qw[j].num==k[i])
            {
                printf("%d ",h);
                if(df==j)
                    break;
                if(x>=0)
                qw[x].r=y;
                if(y<=n)
                qw[y].l=x;
                qw[j].r=df;
                qw[j].l=0;
                qw[df].l=j;
                df=j;
                break;
            }
            j=y;
        }
    }
    return 0;
}
