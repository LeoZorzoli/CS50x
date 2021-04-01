from csv import reader, DictReader
from sys import argv

if len(argv) < 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()

# Read the DNA
with open(argv[2]) as dnafile:
    dnareader = reader(dnafile)
    for row in dnareader:
        dnalist = row

# String
dna = dnalist[0]
# Create Dictionary
sequences = {}

# Extract Sequences
with open(argv[1]) as peoplefile:
    people = reader(peoplefile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break

# Copy in Dictionary
for item in dnaSequences:
    sequences[item] = 1

# Iterate Sequences
for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):
        # Avoid counting again
        while temp > 0:
            temp -= 1
            continue

        # Repetition = Start counting
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l

            # Compares values
            if temp > tempMax:
                tempMax = temp

    # Store Longest
    sequences[key] += tempMax

# Open and iterate Database
with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        # Compare sequences
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")