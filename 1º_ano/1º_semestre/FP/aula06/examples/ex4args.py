# Example: Using command line arguments
#
# This program adds its numerical arguments.
# For example:
#    python3 example5.py 4 2 3 1.7        #-> 10.7
# 
# JMR 2019

import sys

print( sys.argv )   # print the list of all command line arguments

s = 0
for a in sys.argv[1:]:  # scan all proper arguments (excluding argv[0])
    s += float(a)       # convert to float and acumulate

print(s)

print("Try running the program with:")
print("  python3 {} 1 2 1.2e3".format(sys.argv[0]))

