n = int(input())
flag=0
for i in range(10000,1000000):
    a = list(str(i)[:])
    sum = 0
    for j in a:
        sum += int(j)
        if a == list(reversed(a)) and sum == n:
            print(i)
            flag=1
if flag == 0:
    print(-1)
