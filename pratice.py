import write
class sprestaurant(write.Restaurant):
    def __init__(self,restaurant_name,cuisine_type):
        super().__init__(restaurant_name,cuisine_type)
        self.flavors=['1','2','3']
    def show(self):
        print(self.flavors)
class small_res(write.Restaurant):#继承父亲且有油量属性
    def __init__(self,name,type):
        super().__init__(name,type)
        self.oil=50
    def addoil(self):
        self.oil+=50
    def describe_oil(self):
        print(f"the oil has {self.oil} liter")
somewhere1 = sprestaurant('hot','sweat')
somewhere1.describe_restaurant()
somewhere1.show()