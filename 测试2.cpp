#include <stdio.h>
#include <string.h>
void fun(char *x,int n,int *t)
{   int i,k=0;
    x[n]='a';x[n+1]='\0';
    while(x[k]!='a') k++;
    if(k==n){*t=0;}
    else
    {   for(i=k;i<n;i++)
            x[i]=x[i+1];
        x[i-1]='\0';
    }
}
 
main()
{
    char x[20];
    int len,t=1;
    gets(x);
    puts(x);
    len=strlen(x);
    fun(x,len,&t);
    if(t==0) printf("Not exist!\n");
    else    puts(x);
}

