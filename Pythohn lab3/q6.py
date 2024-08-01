n=int(input("enter n->"))
add=0
cnt=1
for i in range(1,n+1):
    if(cnt==1):
        add=1/i
    elif(cnt%2==0):
        print(add,"-",1/i,end="")
        add=add-(1/i)
    else:
        print(add,"+",1/i,end="")
        add=add+(1/i)
    cnt+=1
print()
print(add)