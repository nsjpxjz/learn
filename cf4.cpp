#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
const int MAX=303000;
using namespace std;
int q[MAX],s[MAX];
bool cf(int n,string we)
{

    int h=0,d=0,m=0;
    if(we[0]=='T')
    {
        q[0]=1;
        s[0]=1;
        d++;
    }
    else
    {
        q[0]=0;
        s[0]=0;
        m++;
    }
     for(int i=1; i<n; i++)
        {

            if(we[i]=='T')
            {
                q[i]=1;
                s[i]=s[i-1]+1;
                d++;
            }
            else
            {
                s[i]=s[i-1];
                q[i]=0;
                m++;
            }

        }
        if(d!=2*m)
        {
            return 0;
        }
        for(int i=0; i<n; i++)
        {
            if(q[i]==0&&s[i]<=i-s[i])
            {
                h=1;
                break;
            }
        }
        if(h)
            return 0;
        else return 1;

}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string k;
        getchar();
        cin>>k;
        if(!cf(n,k))
        {
            printf("NO\n");
            continue;
        }
        reverse(k.begin(),k.end());
        if(cf(n,k))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
