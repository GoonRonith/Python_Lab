
input_string = input("Enter a sequence of whitespace-separated words: ")


words = input_string.split()


unique_sorted_words = sorted(set(words))


output_string = ' '.join(unique_sorted_words)


print("Sorted sequence without duplicates: ", output_string)
