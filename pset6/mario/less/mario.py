# Library
from cs50 import get_int

# Check 
while True:
    size = get_int("Height: ")
    if size > 0 and size <= 8:
        break
    
# Variables 

j = 1
z = size

# Draw
while j <= size:
    # Space
    print(" " * (z-1), end="")
    # Col
    print("#" * j)
    j += 1
    z -= 1

