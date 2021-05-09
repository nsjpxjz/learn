sum=0
m=eval(input())
n=eval(input())
a=m
b=n
if int(m)!=m or int(n)!=n:
    print("illegal input")
else:
    for i in range(18):
        c=m+n
        sum+=c
        m=n
        n=c
    print(sum+a+b)