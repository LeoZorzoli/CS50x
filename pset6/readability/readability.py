# Library
from cs50 import get_string

# Prompt
text = get_string("Text: ")

# Variables
letter = 0
word = 1
sentence = 0

# Loop in text
for i in text:
    if i >= 'a' and i <= 'z' or i >= 'A' and i <= 'Z':
        letter += 1
    if i == ' ':
        word += 1
    if i == '.' or i == '!' or i == '?':
        sentence += 1
# Formula       
grade = 0.0588 * (100 * letter / word) - 0.296 * (100 * sentence / word) - 15.8

# Conditions
if grade > 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print("Grade", round(grade))