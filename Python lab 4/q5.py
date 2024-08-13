
input_string = input("Enter a sentence: ")


letter_count = 0
digit_count = 0


for char in input_string:
  
    if char.isalpha():
        letter_count += 1
 
    elif char.isdigit():
        digit_count += 1


print(f"LETTERS {letter_count}")
print(f"DIGITS {digit_count}")
