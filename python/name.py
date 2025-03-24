name=str(input("enter your name: "))
a=len(name)
if(a<4):
    print("enter a valid name")
elif(a>60):
    print("c'mon not again")
else:
    print("nice name")