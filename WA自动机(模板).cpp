#include<cstring>
#include<cstdio>
#define max(a,b) a>b?a:b

const int maxn=1e6+10;

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

char s[151][71],m[maxn];
int cnt,n,a[maxn][26],fail[maxn],point[maxn],hsh[maxn],ans[151];
int que[maxn];

inline void ins(int x)
{
    int now=1,l=strlen(s[x]);
    for(int i=0;i<l;++i)
    {
        int t=s[x][i]-'a';
        if(!a[now][t])a[now][t]=++cnt;
        now=a[now][t];
    }
    hsh[now]=x;
}

void acmatch()
{
    int hd=0,tl=1;
    que[1]=1;point[1]=0;
    while (hd!=tl)
    {
        int now=que[++hd];
        for (int i=0;i<26;++i)
            if(a[now][i])point[a[now][i]]=a[point[now]][i],que[++tl]=a[now][i];
            else a[now][i]=a[point[now]][i];
    }
}

void AC()
{
    int now=1,l=strlen(m);
    for(int i=0;i<l;++i)
    {
        int t=m[i]-'a';
        now=a[now][t];
        for(int j=now;j;j=point[j])if(hsh[j])ans[hsh[j]]++;
    }
}

int main()
{
    n=read();
    for(int i=0;i<26;++i)a[0][i]=1;
    while(n)
    {
        cnt=1;
        for (int i=1;i<=n;++i)
        {
            scanf("%s",s[i]);
            ins(i);
        }
        acmatch();
        scanf("%s",m);
        AC();
        int mx=0;
        for(int i=1;i<=n;++i)mx=max(mx,ans[i]);
        printf("%d\n",mx);
        for (int i=1;i<=n;++i)
        {
            if(mx==ans[i])puts(s[i]);
            ans[i]=0;
        }
        for (int i=1;i<=cnt;i++)
        {
            hsh[i]=point[i]=fail[i]=0;
            for(int j=0;j<26;++j)a[i][j]=0;
        }
        n=read();
    }
    return 0;
}
