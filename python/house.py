house=int(input("enter rate of the house: "))
buyer=bool(input("does the buyer have good credit: "))
if (buyer==1):
    print("rate of the house: " ,0.1*house)
else:
    print("rate of the house: " ,0.2*house)