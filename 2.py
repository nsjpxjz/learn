class student :
    stunum=0
    def __init__(self,name,score):
        self.name=name
        self.score=score
        student.stunum+=1

    def outputname(self) :
        print("name is : " , self.name , "score is : " , self.score)

    def outputnum(self) :
        print("There are " , student.stunum , " students.")


stu1 = student(input(),input())
stu2 = student(input(),input())
stu1.outputnum()
stu1.outputname()
stu2.outputname()