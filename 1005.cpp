#include<bits/stdc++.h>
using namespace std;
int n,m,e,T,ans=9999999,tx,ty,flag;
struct node{
    int x,y;
}q[100010];
int c[110][110];
int l,r;
node k;
void work1(){
    k.x=n;
    k.y=q[l].y;
}
void work2(){
    k.y=m;
    k.x=q[l].x;
}
void work3(){
    k.x=0;
    k.y=q[l].y;
}
void work4(){
    k.y=0;
    k.x=q[l].x;
}
void work5(){
    tx=q[l].x;ty=q[l].y;
    if(tx<=m-ty){
        k.x=0;
        k.y=tx+ty;
    }else{
        k.x=q[l].x-(m-q[l].y);
        k.y=m;
    }
}
void work6(){
    tx=q[l].x;ty=q[l].y;
    if(ty<=n-tx){
        k.y=0;
        k.x=tx+ty;
    }else{
        k.y=q[l].y-(n-q[l].x);
        k.x=n;
    }
}
int main()
{
//  freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&T,&e);
    ans=e;
    q[++r].x=0;
    q[r].y=0;
    c[0][0]=1;
    while(l<r){
        l++;
        for(int i=1;i<=6;i++){
            if(i==1){
                work1();
            }if(i==2){
                work2();
            }if(i==3){
                work3();
            }if(i==4){
                work4();
            }if(i==5){
                work5();
            }if(i==6){
                work6();
            }
            if(!c[k.x][k.y]){
                q[++r].x=k.x;
                q[r].y=k.y;
                c[k.x][k.y]=c[q[l].x][q[l].y]+1;
                if(c[k.x][k.y]>T+1){
                    printf("%d\n",ans);
                    return 0;
                }
                ans=min(ans,abs(k.x+k.y-e));
            }
            if(ans==0){
                printf("0\n");
                return 0;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
} 