#include<bits/stdc++.h>
using namespace std;
int pmt[1000010],nest[1000010];
string s1,s2;

int main()
{
   cin>>s1>>s2;
   int cnt=0;
   for(int i=1,j=0;i<s2.length();i++)
   {
       while(j>=0&&s2[i]!=s2[j])
        j=j?pmt[j-1]:-1;
       pmt[i]=j>=0&&s2[i+1]==s2[j+1]?pmt[j++]:++j;
       nest[i]=j;
   }
   for(int i=0,j=0;i<s1.length();i++)
   {
       while(j>=0&&s1[i]!=s2[j])
        j=j?pmt[j-1]:-1;
        j++;
       if(j==s2.length())
       {
           cout<<i-j+2<<endl;
           j=pmt[j-1];
       }
   }
   for(int i=0;i<s2.length();i++)
    cout<<nest[i]<<' ';
    return 0;
}
