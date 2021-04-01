users = {
    'A':{
        'first' : '1',
        'second' : '2',
},
    'B':{
        'first' : '3',
        'second' : '4',
}
}
print(users['A'])#键值对匹配赋值
for use1,use2 in users.items():
    print(f"\n{use1}:{use2}")