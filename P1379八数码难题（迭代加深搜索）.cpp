#include<iostream>
#include<cstdio>

const int mx[4]={0,1,-1,0};
const int my[4]={1,0,0,-1};
const int INF=40327;

int maxdep=-INF;
int tag[4][4];
bool judge;
int ans=2;
int sx,sy;
int mp[4][4];
int smp[4][4];

int max(int a,int b)
{
    return a>b?a:b;
}

void read()
{
    judge=false;
    int cur=0;
    puts("请输入初始数组");
    while(cur<9)
    {
        int ch=getchar();
        while(ch<'0'||ch>'8')ch=getchar();
        mp[cur/3+1][cur%3+1]=smp[cur/3+1][cur%3+1]=ch-'0';
        if(ch=='0')sx=cur/3+1,sy=cur%3+1;
        cur++;
    }
    puts("请输入目标数组");
    cur=0;
    while(cur<9)
    {
        int ch=getchar();
        while(ch<'0'||ch>'8')ch=getchar();
        tag[cur/3+1][cur%3+1]=ch-'0';
        cur++;
    }
}

void output()
{
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            printf("%d ",mp[i][j]);
        }
        putchar(10);
    }
    putchar(10);
}

bool check()//判重
{
    output();
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            if(mp[i][j]!=tag[i][j])return false;
        }
    }
    return true;
}

bool test(int depth)//剪枝：当不同的点+深度超过当前步数时则在当前步数内无法完成八数码难题
{
    int difference=0;
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            if(tag[i][j]!=mp[i][j])
            {
                ++difference;
                if(difference+depth>ans)return false;
            }
        }
    }
    return true;
}

bool check2()
{
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            if(mp[i][j]!=smp[i][j])return false;
        }
    }
    return true;
}

bool star(int depth,int x,int y,int pr)//pr记录上一次行动若i+pr=3则这次行动将会返回到此前状态
{
    maxdep=max(maxdep,depth);
    printf("目前层数：%d\n",depth);
    if (depth == ans) {
        if (check())judge = true;
        return true;
    }
    if (check2()&&depth!=0)return false;
    if (judge)return true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + mx[i], ny = y + my[i];
        if (nx > 3 || nx < 1 || ny > 3 || ny < 1 || pr + i == 3)continue;
        std::swap(mp[nx][ny], mp[x][y]);
        output();
        if (test(depth))return star(depth + 1, nx, ny, i);
        std::swap(mp[nx][ny], mp[x][y]);
    }
    return true;
}
void solve()
{
    if(check())
    {
        printf("0\n");
        return;
    }
    while(++ans)
    {
        if(!star(0,sx,sy,-1)){puts("No solution!");printf("The depth is: %d\n",maxdep);break;}
        if(judge)
        {
            printf("%d\n",ans);
            break;
        }
    }
}

int main()
{
    read();
    solve();
    return 0;
}