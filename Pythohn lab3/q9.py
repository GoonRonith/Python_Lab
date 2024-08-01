n=int(input("enter n"))
gap=1
cnt=1

for i in range(2,n+1):
    line=(i*1)+cnt
    cnt+=1


for i in range(1,n+1):
    print()
    if(i==1):
        for j in range(n-1):
            print(" ",end="")
        print(".")
    elif(i==n):
        for j1 in range(n-i):
            print(" ",end="")
        print("/",end="")
        for j2 in range(gap):
            print(" ",end="")
        print("\\")
        for j3 in range(line):
            print("-",end="")
    else:
        for j1 in range(n-i):
            print(" ",end="")
        print("/",end="")
        for j2 in range(gap):
            print(" ",end="")
        print("\\")
        gap+=2




