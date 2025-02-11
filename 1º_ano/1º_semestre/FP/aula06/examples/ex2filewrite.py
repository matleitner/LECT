# Example: Writing a file

# Create a fle points.txt containing the lines from drawing.txt
# that are fully alphabetic.

# Version 1
"""
f = open("drawing.txt")
f2 = open("points.txt", "w")
for line in f:
    line = line.strip() # remove whitespace from the both ends
    if line.isalpha():
        print(line, file=f2)  #EQUIV: f2.write(line + "\n")
f2.close()  # REMEMBER to close! 
f.close()   # REMEMBER to close!
"""

# Version 2: using with statement (safer)

with open("drawing.txt") as f, open("points.txt", "w") as f2:
    for line in f:
        line = line.strip() # remove whitespace from the both ends
        if line.isalpha():
            print(line, file=f2)  #EQUIV: f2.write(line + "\n")
# NO NEED to call close()!

