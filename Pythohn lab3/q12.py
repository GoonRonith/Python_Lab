n=int(input("enter n->"))
ans=0
for i in range(1,n+1):
    print()
    flag=False
    for j in range(1,n):
        if(flag==False):
           print(f"{i} 1",end=" ")
           ans=i*1
           mul=ans
           flag=True
        else:
            print(ans,end=" ")
            ans*=mul

        