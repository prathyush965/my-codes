weight=int(input("enter your weight: "))
kol=input("(k)g or (l)bs: ")
if kol.lower() == 'k':
    con=weight/0.45
    print("you weigh",con,"lbs")
else:
    con=weight*0.45
    print("you weigh",con,"kg")