#include <iostream>
#include<cstdio>
const int MAX=505000;
#define lowbit(x) ((x)&(-x))
using namespace std;
int m,n,tree[MAX];
inline void add(int i,int x)
{
    for(int p=i;p<MAX;p+=lowbit(p))
        tree[p]+=x;
}
inline int que(int a)
{
    int ans=0;
    for(int i=a;i;i-=lowbit(i))
        ans+=tree[i];
    return ans;
}
inline int qua(int b,int c)
{
    return que(c)-que(b-1);
}
int main()
{
    int t;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        add(i,t);
    }
    while(n--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        switch (a)
        {
        case 1:
            add(b,c);
            break;
        case 2:
            printf("%d\n",qua(b,c));
            break;
        }
    }
    return 0;
}
