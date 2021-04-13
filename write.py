class Restaurant:
    def __init__(self,restaurant_name,cuisine_type):
        self.name = restaurant_name
        self.type = cuisine_type
    def describe_restaurant(self):
        print(f"The restaurant's name is {self.name}")
        print(f"{self.name.title()}'s cuisine type is {self.type}")
    def open_restaurant(self):
        print("Now the restaurant is opening")
class small_res(Restaurant):#继承父亲且有油量属性
    def __init__(self,name,type):
        super().__init__(name,type)
        self.oil=50
    def addoil(self):
        self.oil+=50
    def describe_oil(self):
        print(f"the oil has {self.oil} liter")
A=small_res('small','meat')
A.describe_restaurant()
A.addoil()
A.describe_oil()