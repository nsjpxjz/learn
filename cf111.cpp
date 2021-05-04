    #include<bits/stdc++.h>
    using namespace std;
    #define LL long long
    #define MOD 1000000007 //10^9 + 7
    LL t,a[110],s[110];
    int main()
    {
        cin>>t;
        while(t--)
        {
            memset(s,0,sizeof(s));
           int n,x,b;
            cin>>n>>x;
            for(int i=1;i<=n;i++)
                cin>>a[i];
                sort(a+1,a+1+n);
            for(int i=1;i<=n;i++)
            {
                s[i]=s[i-1]+a[i];
                if(s[i]==x&&i!=n)
                {
                    int k=a[i];
                    a[i]=a[i+1];
                    a[i+1]=k;
                    b=1;
                    break;
                }
                else if(s[i]==x&&i==n)
                {
                    b=0;
                    break;
                }

            }
            if(b)
            {
                printf("YES\n");
                for(int i=1;i<=n;i++)
                    printf("%lld ",a[i]);
                printf("\n");
            }
            else printf("NO\n");

        }
        return 0;
    }
