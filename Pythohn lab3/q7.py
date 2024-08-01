import math
n=int(input("enter n->"))
x=int(input("enter x->"))
def factorial(number):
    fact=1
    for i in range(1,number+1):
        fact=fact*i
    return fact
add=0
cnt=1

for i in range(1,n+1):
    if(i==1):
        add=x
        print(f"{x}*{cnt}/{cnt}!",end="")
    elif(i%2==0):
        print("-",f"{x}*{cnt}/{cnt}!",end="")
        add=add-(x*cnt)/factorial(cnt)
    else:
        print("+",f"{x}*{cnt}/{cnt}!",end="")
        add=add+(x*cnt)/factorial(cnt)
    cnt+=2
print()
print(f"sin({add}) => {math.sin(math.radians(add))}")
