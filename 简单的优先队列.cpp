#include <iostream>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
int n,a[10100],ans;
priority_queue<int,vector<int>,greater<int> >q;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        q.push(a[i]);
    }
    int t1=q.top();
    q.pop();
    int t2=q.top();
    q.pop();
    while(1)
    {
        ans+=t1+t2;
        q.push(t1+t2);
        t1=q.top();
        q.pop();
        if(!q.empty())
        {
            t2=q.top();
            q.pop();
        }
        else break;
    }
    cout<<ans;

    return 0;
}
