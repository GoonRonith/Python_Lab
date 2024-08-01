def calculate_slope(x1,y1,x2,y2):
    slope=(y2-y1)/(x2-x1)
    return slope


x1=int(input("enter x1 co-ordinate"))
x2=int(input("enter x2 co-ordinate"))
y1=int(input("enter y1 co-ordinate"))
y2=int(input("enter y2 co-ordinate"))


print(f"slope is {calculate_slope(x1,y1,x2,y2)}")