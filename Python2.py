s=[value**2 for value in range(1,10,3)]
names=['liu','li','yang','zhao','sun']
a=[1,5,6,7,8,2,3]
a.append(10)
a.pop(3)
a.remove(1)
print(a)
print(min(a))
print(s)
for name in names:
    print(f"hello,{name.title()}.")