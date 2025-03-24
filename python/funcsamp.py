def add():
    return num1+num2
def sub():
    return num1-num2
def multi():
    return num1*num2
def div():
    return num1/num2
#main
while True:
    num1=int(input("enter a number: "))
    num2=int(input("enter an another number: "))
    choice=(input("""
                    1. addition
                    2. subtraction
                    3. multiplication 
                    4. division
                   Enter a function:(choose the number): """))
    if choice.lower()=='quit':
        print("fine")
        break
    if choice.isdigit():
        choice=int(choice)
        if choice==1:
            print(add())
        elif(choice==2):
             print(sub())
        elif(choice==3):
            print(multi())
        elif(choice==4):
            print(div())
        else:
            print("it literally said to choose a number")
