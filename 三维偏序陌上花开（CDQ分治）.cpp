#include<cstdio>
#include<algorithm>
#define maxn 200020
using namespace std;
inline int read()
{
    char ch=getchar();
    int in=0,fu=1;
    while(ch!='-'&&(ch>'9'||ch<'0'))ch=getchar();
    if(ch=='-'){fu=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){in*=10;in+=ch-'0';ch=getchar();}
    return in*fu;
}
inline void write(int x)
{
    if(x/10==0){putchar(x+'0');return;}
    write(x/10);
    putchar(x%10+'0');
}
struct aa
{
    int a,b,c,ans,cnt;
}s[maxn],ss[maxn];
int n,m,k,maxx,ans[maxn],tp;
int sz[maxn];

bool cmp1(aa x,aa y)
{
	if(x.a==y.a)
	{
		if(x.b==y.b)return x.c<y.c;
		else return x.b<y.b;
	}
	else return x.a<y.a;
}
bool cmp2(aa x,aa y)
{
	if(x.b==y.b)
	return x.c<y.c;
	else return x.b<y.b;
}
inline int lowbit(int x)
{
    return x&-x;
}
inline void add(int x,int y)
{
    while(x<=maxx)
	{
		ans[x]+=y;
		x+=lowbit(x);
	}
}
inline int query(int x)
{
	int sum=0;
	while(x)
	{
		sum+=ans[x];
		x-=lowbit(x);
	}
	return sum;
}
inline void cdq(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	sort(ss+l,ss+mid+1,cmp2);
	sort(ss+mid+1,ss+r+1,cmp2);
	int i,j=l;
	for(i=mid+1;i<=r;++i)
	{
		while(ss[i].b>=ss[j].b&&j<=mid)
		{
			add(ss[j].c,ss[j].cnt);
			j++;
		}
		ss[i].ans+=query(ss[i].c);
	}
	for(i=l;i<j;++i)
	add(ss[i].c,-ss[i].cnt);
}
int main()
{
    n=read();
    k=read();
    maxx=k;
    for(int i=1;i<=n;++i)
    {
        s[i].a=read(),s[i].b=read(),s[i].c=read();
    }
    sort(s+1,s+1+n,cmp1);
    for(int i=1;i<=n;++i)
	{
		++tp;
		if(s[i].a!=s[i+1].a||s[i].b!=s[i+1].b||s[i].c!=s[i+1].c)
		{
			++m;
			ss[m].a=s[i].a;
			ss[m].b=s[i].b;
			ss[m].c=s[i].c;
			ss[m].cnt=tp;
			tp=0;
		}
	}
	cdq(1,m);
	for(int i=1;i<=m;++i)ans[ss[i].ans+ss[i].cnt-1]+=ss[i].cnt;
	for(int i=0;i<n;++i){write(ans[i]);printf("\n");}
	return 0;
}
