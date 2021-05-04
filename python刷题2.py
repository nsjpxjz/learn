temp = input("输入带符号的温度值:")
a = eval(temp[0:-1])
if temp[-1] in ['F','f']:
    c = a-32/1.8
    print('转化后的温度为{:.2f}C'.format(c))
elif temp[-1] in ['C','c']:
    f = 1.8*a + 32
    print('转化后的温度为{:.2f}F'.format(f))
else:
    print("输入格式错误")