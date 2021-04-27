a=[]
n=int(input())
for i in range(0,n):
    b=[]
    for j in range(0,i+1):
        if j==0:
            b.append(1)
        elif j!=i:
            b.append(0)
        else:
            b.append(1)
    a.append(b)
for i in range(0,n):
    for j in range(1,i):
            a[i][j]=a[i-1][j]+a[i-1][j-1]
for num in a:
    for num2 in num:
        print(num2,end=' ')
    print('\n',end='')
