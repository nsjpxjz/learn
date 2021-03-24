my_foods=['pizza','falafel','carrot cake']
foods = my_foods[:]#此时foods复制了列表
my_foods.append('rice')
foods.append('noodles')
print(my_foods)
print(foods)
numbers=[1,2,3,4,5,6]
num2=numbers#此时num2复制了对numbers的索引
numbers.append(7)
num2.append(8)
print(numbers)
print(num2)