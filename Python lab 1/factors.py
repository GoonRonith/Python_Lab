#factors
n=10
print(n)
print("factors : ")
for i in range(1,n+1):
    if n%i==0:
        print(i,end=' ')
