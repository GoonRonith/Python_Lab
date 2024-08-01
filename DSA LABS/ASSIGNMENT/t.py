def calculate (r, unit, arr, n):
    if n == 0:
        return -1 
        
    totalFoodRequired = r * unit 
    foodTillNow = 0 
    house = 0 
        
    for house in range (n):
        foodTillNow += arr[house] 
        print("jj")
        if foodTillNow>=totalFoodRequired:
            break 
    if totalFoodRequired > foodTillNow:
        return 0
    return house + 1
    

r = int (input ("enter r"))
unit = int (input ("entr u"))
n = int (input ("enter n"))
  
arr = []
for i in range(0,n):
    x=int(input("Enter :"))
    arr.append(x)
print (calculate (r, unit, arr, n))