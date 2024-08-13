
lines = []


print("Enter lines of text (press Enter without typing anything to finish):")

while True:

    line = input()
    
   
    if not line:
        break
    
  
    lines.append(line)


print("\nCapitalized Lines:")
for line in lines:
    print(line.upper())
