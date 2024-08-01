#div by 7 but not 5
l=1000
h=2000
print(" div by 7 but not 5")
for n in range(l,h+1):
    if(n%7==0)and(n%5!=0):
        print(n,end=' ')
