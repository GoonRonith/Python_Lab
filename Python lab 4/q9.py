
def reverse_string(s):
    return s[::-1]


def is_palindrome(s):
    return s == s[::-1]


def ends_with(s, substring):
    return s.endswith(substring)


def capitalize_first_letter(s):
    return s.title()


def is_anagram(s1, s2):
    return sorted(s1) == sorted(s2)


def remove_vowels(s):
    vowels = "aeiouAEIOU"
    return ''.join([char for char in s if char not in vowels])


def longest_word_length(sentence):
    words = sentence.split()
    return max(len(word) for word in words)


input_string = input("Enter a string: ")


reversed_string = reverse_string(input_string)
palindrome_check = is_palindrome(input_string)
specific_substring = input("Enter a substring to check if the string ends with it: ")
ends_with_substring = ends_with(input_string, specific_substring)
capitalized_string = capitalize_first_letter(input_string)
anagram_string = input("Enter another string to check if it is an anagram: ")
anagram_check = is_anagram(input_string, anagram_string)
string_without_vowels = remove_vowels(input_string)
longest_word_len = longest_word_length(input_string)


print("\nResults:")
print(f"1. Reversed String: {reversed_string}")
print(f"2. Is Palindrome: {'Yes' if palindrome_check else 'No'}")
print(f"3. Ends with '{specific_substring}': {'Yes' if ends_with_substring else 'No'}")
print(f"4. Capitalized String: {capitalized_string}")
print(f"5. Is Anagram: {'Yes' if anagram_check else 'No'}")
print(f"6. String without Vowels: {string_without_vowels}")
print(f"7. Length of Longest Word: {longest_word_len}")
