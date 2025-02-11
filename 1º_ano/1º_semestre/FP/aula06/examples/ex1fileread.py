# Example: Reading a file line-by-line

# Version 1: using readline in a while loop
"""
f = open("drawing.txt", "r")
while True:
    line = f.readline()
    if len(line)==0: break
    print(len(line), line)
f.close()   # REMEMBER to close!
"""

# Version 2: using a for loop to iterate the lines in the file
"""
f = open("drawing.txt", "r")
for line in f:
    print(len(line), line)
f.close()   # REMEMBER to close!
"""

# Version 3: Same thing, but using a with statement
with open("drawing.txt", "r") as f:
    print("Primeira", f.readline())
    for line in f:
        line = line.rstrip()
        print(len(line), line)
# NO NEED to call close()!

