#palindrome
n=121
print(n)
temp=n
r=0
while n>0:
    rem=n%10
    r=r*10+rem
    n=n//10
print(r)
if(temp==r):
    print("palidrome")
else:
    print("not")
