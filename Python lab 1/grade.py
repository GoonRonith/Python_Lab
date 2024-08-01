#grade card
n=int(input("enter percentage :"))

if n>=90 and n<=100:
    print("A")
elif n>=80 and n<90:
    print("B")
elif n>=70 and n<80:
    print("C")
elif n>=60 and n<70:
    print("D")
elif n>=40 and n<60:
    print("E")
elif n>0 and n<40:
    print("F")
else:
    print("wrong")
