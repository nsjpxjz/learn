#include <iostream>
#define LL long long
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        LL k=0,p[2020];
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>p[i],k^=p[i];
        if(k==0)
            cout<<"YES"<<endl;
        else
        {
            LL j,h=0,r=0,i=0,l=0;
            for(;i<=n;i++)
            {
                l^=p[i];
                if(l==k)
                    break;
            }
              j=i+1;
            for(; j<=n; j++)
            {
                r^=p[j];
                if(r==k)
                {
                    r=0;
                    h=j;
                }
            }
            if(h==n||(r==0&&h))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;



        }

    }
    return 0;
}
