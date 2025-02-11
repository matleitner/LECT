# Example: Functions with lists
# jmr 2018, 2024

# Read N numbers and return them in a list.
def inputNFloats(prompt, N):
    l = []
    for x in range(N):
        r = float(input(prompt))
        l.append(r)
    return l

# Read numbers until a sentinel string and return them in a list.
# (The sentinel is an optional parameter.)
def inputFloats(prompt, sentinel=""):
    l = []
    while True:
        s = input(prompt)
        if s == sentinel: break
        r = float(s)
        l.append(r)
    return l


# A function that modifies the elements in a list.
def UP(lst):
    for i in range(len(lst)):
        lst[i] += 1
    # returns no result but changes the list as a side-effect!

# Do you think this function modifies the elements in a list?
def notUP(lst):
    for elem in lst:
        elem += 1
    # No, not really! Why?

# Test the functions:

#temp = inputNFloats("temperatura? ", 3)
#print(max(temp))

l = inputNFloats("valor? ", 4)
print("   ORIGINAL:", l)
UP(l)
print("   AFTER UP:", l)
notUP(l)
print("AFTER notUP:", l)

