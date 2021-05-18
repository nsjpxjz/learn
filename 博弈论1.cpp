#include<cstdio>

int n;

int main()
{
    while(~scanf("%d",&n)&&n) {
        if (n<=2) {
            puts("Alice");
            continue;
        }
        else puts("Bob");
    }
    return 0;
}