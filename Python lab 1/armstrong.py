#armstrong number
n=1634
temp=n
l=len(str(n))
sum=0
while n!=0:
    r=n%10
    sum=sum+(r**l)
    n=n//10
if(temp==sum):
    print("armstrong number")
else:
    print("not")
