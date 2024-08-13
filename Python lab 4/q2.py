
input_string = input("Enter a comma-separated sequence of words: ")


words = input_string.split(',')


words_sorted = sorted(words)


output_string = ','.join(words_sorted)


print("Sorted sequence: ", output_string)
