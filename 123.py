x=0
a,b = map(int,input().split(' '))
for i in range(1,a):
    flag = 0
    if 2*i+(a-i)*4==b:
        flag = 1
        x=i
        break
int(x)
if flag == 1:
    print(x,a-x)
else:
    print("Data Error!")