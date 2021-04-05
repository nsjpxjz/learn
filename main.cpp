#include <iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int n,l;
string c,a;
bool ban(string s)
{
    int l=s.size();
    for(int  i=0,j=l-1; i<=j; i++,j--)
    {
        if(s[i]!=s[j])
            return 0;
    }
        return 1;
}
int main()
{
    cin>>n;
    a+='a';
    for(int i=1; i<=n; i++)
    {
        bool k=1;
        string s;
        cin>>c;
        l=c.length();
        for(int i=0;i<l&&k;i++)
        {
            if(c[i]!='a')
            {
                 k=0;
                 break;
            }
        }
        if(k==1)
        {
            printf("NO\n");
            continue;
        }
        for(int i=0; i<l; i++)
        {
            s=c;
            s.insert(i,a);
            if(!ban(s))
            {
                cout<<"YES"<<endl<<s<<endl;
                break;
            }
             if(s[i+1]=='a')
             while(i+1<l&&s[i+2]=='a')
                i++;
        }

    }
    return 0;
}
