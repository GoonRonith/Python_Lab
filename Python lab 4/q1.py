
input_string = input("Enter a string: ")


length_of_string = len(input_string)
print(f"Length of the string: {length_of_string}")


substring = "country"
if substring in input_string:
    print(f"The substring '{substring}' is found in the input string.")
else:
    print(f"The substring '{substring}' is not found in the input string.")


words = input_string.lower().split()


word_count = {}


for word in words:
    if word in word_count:
        word_count[word] += 1
    else:
        word_count[word] = 1


print("Occurrences of each word in the string:")
for word, count in word_count.items():
    print(f"'{word}': {count}")
