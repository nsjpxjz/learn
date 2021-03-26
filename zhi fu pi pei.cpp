#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[2020],b[2020];
int k[2020][2020];
int main()
{
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    for(int i=1; i<=strlen(a); i++)
    {
        k[i][0]=i;
    }
    for(int j=1; j<=strlen(b); j++)
    {
        k[0][j]=j;

    }
    for(int i=0; a[i]; i++)
        for(int j=0; b[j]; j++)
        {
            if(a[i]==b[j])
                k[i+1][j+1]=k[i][j];
            else
            {
                k[i+1][j+1]=min(min(k[i+1][j],k[i][j+1]),k[i][j])+1;
            }
        }
    cout<<k[strlen(a)][strlen(b)];
    return 0;
}
