#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#define N 300030
using namespace std;
int i,j,m,n,p,k,x,a[N];
long long ans;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(i=0;i<31;++i){
        for(j=1;j<=n;j=k){
            if((a[j]>>i)&1){
                for(k=j;k<=n&&((a[k]>>i)&1);++k);
                int len=k-j;
                ans+=(long long)len*(len+1)/2*(1<<i);
            }
            else{
                k=j+1;
            }
        }
    }
    printf("%lld\n",ans);
}
