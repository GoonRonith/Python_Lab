#fibonacci series
l=10
n1=0
n2=1
print("fibonacci series")
for i in range(2,l):
    n3=n1+n2
    n1=n2
    n2=n3
    print(n3,end=' ')
