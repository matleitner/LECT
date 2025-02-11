# Example: Sorting with multiple criteria.
# Copy each statement and execute in INTERACTIVE mode!

# JMR 2018

L = ["Mario", "Carla", "anabela", "Maria", "nuno"]

# Sort lexicographically: 
sorted(L)

# Sort in reverse order:
sorted(L, reverse=True)

# Sort by length:
sorted(L, key=len)
    # sorted applies the function `len` to each element in L,
    # then sorts according to the result!

# Case-insensitive sort:
sorted(L, key=str.lower)  # key=str.casefold is even better

# This works because
str.lower("Mario") == "Mario".lower() == "mario"
str.lower("Maria") == "maria"


# Problem: How to sort L by length, then lexicographically if length is equal?
# Solution: Create a function that returns a tuple with length, then string.
#   Use that function as the key function to sort by.
def byLenThenLex(s):
    return (len(s), s)

# Test:
byLenThenLex("Mario") == (5, "Mario")
byLenThenLex("Maria") == (5, "Maria")

sorted(L, key=byLenThenLex)



D = [(1910, 10, 5, 'Republic'),
    (1, 12, 25, 'Christmas'),
    (1974, 4, 25, 'Liberty'),
    (1640, 12, 1, 'Restoration')]

# Lexicographic tuple sort:
sorted(D)

# Sort D by name of Holiday:
def getName(t):
    return t[-1]     # name is last field of tuple

sorted(D, key=getName)

# Sort D by (month,day), ignoring year:
def getMonthDay(t):
    return t[1:3]

sorted(D, key=getMonthDay)


# Instead of defining small functions to use just once,
# we can create an anonymous function with a lambda expression and pass it on.

# Sort D by name of Holiday:
sorted(D, key= (lambda t: t[-1]) )

# Sort D by (month,day), ignoring year:
sorted(D, key=lambda t: t[1:3] )


# Sort L by length, then case-insensitive:
sorted(L, key=lambda s: (len(s), s.lower()) )

