def JC (n):
    m=1
    while n>0:
        m*=n
        n-=1
    return m
#求阶乘函数
a = eval(input())
b = eval(input())
c = eval(input())
a1=JC(a)
b1=JC(b)
x=JC(a+b)
result1=(a1+b1)/x
print(f"result1 = {result1}")
judge = b**2 -4*a*c
if judge < 0 :
    print("can't get result2")
else :
    result2 = (b ** 2 - 4 * a * c) ** 0.5
    print(f"result2 = {result2}")