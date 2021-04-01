# Library
from cs50 import SQL
from sys import argv

# Check
if len(argv) < 2:
    print("usage error, roster.py houseName")
    exit()

# Open Database
db = SQL("sqlite:///students.db")
students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", argv[1])

# Print each Person
for student in students:
    if student['middle'] != None:
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")