#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,a[505][505],dx[2]= {0,1},dy[2]= {-1,0},bt[505],k[505];
void cf(int x)
{
    for(int i=1; i<=x; i++)
    {

        int t=k[i];
        if(!bt[t])
            continue;
        int xx=n-x+i,yy=i;
        for(int j=0; j<2; j++)
        {
            int xc=dx[j]+xx,yc=dy[j]+yy;
            if(xc<=n&&yc>0&&a[xc][yc]==0)
            {
                a[xc][yc]=t;
                bt[t]--;
                break;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i][i],bt[i]=i-1;
    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            k[j]=a[n-i+j][j];
        }
        cf(i);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
