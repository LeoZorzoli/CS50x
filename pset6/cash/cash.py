# Cs50 Library
from cs50 import get_float
# Math library for math.floor
import math

# Check
while True:
    cash = get_float("How much change is owed?\n")
    if cash > 0:
        break

# Variables   
cents = round(cash * 100)
mon = 0
coins = 0
resto = 0

# If 25
if cents >= 25:
    mon = cents / 25
    coins = math.floor(mon)
    cents = cents - 25 * coins
    resto = coins
# If 10
if cents >= 10:
    mon = cents / 10 
    coins = math.floor(mon)
    cents = cents - 10 * coins
    resto = resto + coins
# If 5   
if cents >= 5:
    mon = cents / 5
    coins = math.floor(mon)
    cents = cents - 5 * coins
    resto = resto + coins
# If 1 
if cents >= 1:
    mon = cents / 1
    coins = math.floor(mon)
    cents = cents - 1 * coins
    resto = resto + coins
# Print   
print(resto)