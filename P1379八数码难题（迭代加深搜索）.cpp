#include<iostream>
#include<cstdio>

bool judge;
int ans=2;
const int tag[4][4]={{0,0,0,0},{0,1,2,3},{0,8,0,4},{0,7,6,5}};
int sx,sy;
int mp[4][4];
const int mx[4]={0,1,-1,0};
const int my[4]={1,0,0,-1};

void readmp()
{
    judge=false;
    char ch[10];
    scanf("%s",ch);
    for(int i=0;i<9;++i)
    {
        mp[i/3+1][i%3+1]=ch[i]-'0';
        if(ch[i]=='0')sx=i/3+1,sy=i%3+1;
    }
}

bool check()
{
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            if(mp[i][j]!=tag[i][j])return false;
        }
    }
    return true;
}

bool test(int step)
{
    int difnum=0;
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            if(tag[i][j]!=mp[i][j])
            {
                ++difnum;
                if(difnum+step>ans)return false;
            }
        }
    }
    return true;
}

void Astar(int step,int x,int y,int pr)
{
    if(step==ans)
    {
        if(check())judge=true;
        return;
    }
    if(judge)return;
    for(int i=0;i<4;++i)
    {
        int nx=x+mx[i],ny=y+my[i];
        if(nx>3||nx<1||ny>3||ny<1||pr+i==3)continue;
        std::swap(mp[nx][ny],mp[x][y]);
        if(test(step))Astar(step+1,nx,ny,i);
        std::swap(mp[nx][ny],mp[x][y]);
    }
}

int main()
{
    readmp();
    if(check())
    {
        printf("0\n");
        return 0;
    }
    while(++ans)
    {
        Astar(0,sx,sy,-1);
        if(judge)
        {
            printf("%d\n",ans);
            break;
        }
    }
    return 0;
}
