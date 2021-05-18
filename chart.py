from random import choice
import matplotlib.pyplot as plt
plt.style.available
class randwalk:
    """模拟随机漫步"""
    def __init__(self,numbers):
        self.walkstep=numbers
        self.x=[0]
        self.y=[0]
    def fillwalk(self):
        while len(self.x)<self.walkstep:
            """随机前往一个方向并随机选择步数"""
            direction_x = choice([1,-1])
            distance_x = choice([0,1,2,3,4])
            step_x = distance_x*direction_x
            direction_y = choice([1,-1])
            distance_y = choice([0,1,2,3,4])
            step_y = distance_y*direction_y
            if step_x and step_y == 0:
                continue
            else:
                x1 = self.x[-1] + step_x
                y1 = self.y[-1] + step_y
                self.x.append(x1)
                self.y.append(y1)
walk = randwalk(5000)
walk.fillwalk()
x=walk.x
y=walk.y
image,chart = plt.subplots()
chart.scatter(x,y,s=10,c='red')
plt.show()