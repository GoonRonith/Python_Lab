import math

# Calculate sin(60 degrees)
sin_60 = math.sin(math.radians(60))

# Calculate cos(pi radians)
cos_pi = math.cos(math.pi)

# Calculate sin(0.8660254037844386)
sin_value = math.sin(0.8660254037844386)

# Calculate tan(90 degrees) - Note: This will result in a very large number
# or an error because tan(90 degrees) is undefined.
try:
    tan_90 = math.tan(math.radians(90))
except ValueError as e:
    tan_90 = str(e)

print(f"sin(60 degrees) = {sin_60}")
print(f"cos(pi radians) = {cos_pi}")
print(f"sin(0.8660254037844386) = {sin_value}")
print(f"tan(90 degrees) = {tan_90}")
