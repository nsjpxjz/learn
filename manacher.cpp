#include<cstdio>
#include<cstring>
#define maxn 33000003
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

char str1[maxn],str2[maxn];
int p[maxn];

int init()
{
    int len=strlen(str2);
    int cur=2;
    str1[0]='^';
    str1[1]='#';
    for (int i=0;i<len;i++)
    {
        str1[cur++]=str2[i];
        str1[cur++]='#';
    }
    str1[cur]='&';
    return cur;
}

int mnc()
{
    int len=init(),mid=1,maxx=1,ans=-1;
    for (int i=1;i<len;i++)
    {
        if(i<maxx)p[i]=min(maxx-i,p[mid*2-i]);
        else p[i]=1;
        while(str1[i-p[i]]==str1[i+p[i]])p[i]++;
        if (maxx<i+p[i]) mid=i,maxx=i+p[i];
        ans=max(ans,p[i]-1);
    }
    return ans;
}

int main()
{
    scanf("%s",str2);
    printf("%d",mnc());
}