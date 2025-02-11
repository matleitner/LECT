# Example: Sets
# These examples are meant to be executed in Python INTERACTIVE MODE.
# Copy and execute each line and check the results.

# JMR, 2018

# A list of strings:
args = ['apple', 'dell', 'ibm', 'hp', 'sun']

# A set can be defined by extension:
num = {32, 6, 5, 13, 17}
num
type(num)

# Sets are collections, and have a size (length):
len(num)

# We can create sets by converting from other types:
lst = [2, 5, 1, 5, 4]
s = set( lst )
s
len(s)

bolas = set( range(1, 51) )
bolas

# We can check whether an element is a member of a set:
5 in num
9 in num
9 not in num

# We can check if a set is a subset of another:
A = {3, 6, 7}
B = {6, 7, 8, 9}

{3, 7} < A     # is a strict subset?
A < A
A <= A
A.issubset(A)   # equivalent to `A <= A`!
B > {7, 9}     # is a strict superset?

# We can do set intersection, union, difference and symmetric-difference:
A = {3, 6, 7}
B = {6, 7, 8, 9}
A & B
A & B   # intersection
A | B   # union
A - B   # set difference
A ^ B   # set symmetric-difference

# Sets are mutable:
num = {32, 6, 5, 13, 17}
bak = num       # bak points to same object as num
bak is num

num.add(87)     # adding a new element to the set
num.remove(5)   # removing an element
num.discard(99) # also removes, but no error even if element is not there!

num             # object pointed to by num was modified
bak             # bak points to the same object (aliasing)

# We can update a set by union, intersection, difference with another set:
num |= {99, 88}
num -= {1, 6, 17}
num
bak
num is bak

num = num | {77}    # This creates a new object
num is bak          # no longer the same
bak
num

bak = num
num.update({2,4,5})     # same as |=
num
bak

# Sets can be defined by comprehension, too:
{ x+100 for x in num }
{ x+100 for x in [3 ,7, 3, 8] }
