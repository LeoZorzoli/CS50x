# Library
from cs50 import SQL
from csv import reader
from sys import argv

# Open the database
db = SQL("sqlite:///students.db")

# Check
if len(argv) < 2:
    print("usage error, import.py characters.csv")
    exit()

# Open CSV
with open(argv[1], newline='') as charactersFile:
    characters = reader(charactersFile)
    for character in characters:
        if character[0] == 'name':
            continue

        # Split Name
        fullName = character[0].split()
        
        # Insert in Database
        if len(fullName) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], None, fullName[1], character[1], character[2])

        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], fullName[1], fullName[2], character[1], character[2])