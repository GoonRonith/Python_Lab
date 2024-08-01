#perfect number
n=28
s=0
for i in range(1,n):
    if n%i==0:
        s=s+i
if(s==n):
    print("perfect number")
else:
    print("not")
