def save_car(manufacturer,type1,**message):
    car = {}
    car['origin']=manufacturer
    car['type']=type1
    for name,value in message.items():
        car[name]=value
    return car
car = save_car('subaru','outback',color='blue',tow_package=True)
print(car)