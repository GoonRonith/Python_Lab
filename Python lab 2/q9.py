def decimal_to_binary(n):
    if n == 0:
        return "0"
    
    binary_num = ""
    while n > 0:
        remainder = n % 2
        binary_num = str(remainder) + binary_num
        n = n // 2
    
    return binary_num

# Example usage:
decimal_number = 30
binary_representation = decimal_to_binary(decimal_number)
print(f"The binary representation of {decimal_number} is {binary_representation}")
