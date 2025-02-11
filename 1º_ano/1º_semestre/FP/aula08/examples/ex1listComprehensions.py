# Example: Using list comprehensions.
# These examples are meant to be executed in Python INTERACTIVE MODE.
# Copy and execute each line and check the results.

# JMR, 2018

# A list of numbers, defined by extension:
lst = [2, 5, -3, 1, -2, 4]

## Map operations

# Creating a list derived from lst, the traditional way:
lst2 = []
for v in lst:
    lst2.append(v**2)

lst2

# Same thing, using a list comprehension:
lst2 = [ x**2 for x in lst ]
lst2

# More examples:
[ x-2 for x in lst2 ]

args = ['apple', 'dell', 'ibm', 'hp', 'sun']
[ s.upper() for s in args ]

# All of the above are examples of so called _map_ operations:
# Creating a list by applying some function to every element of another list.
# This is quite common in different applications.
# You can also do it by using the `map` function:
list( map(str.upper, args) )
# but we'll see that later in the course.


## Filter operations

# Make a list of the elements in lst that are even:
[ x for x in lst if x%2==0 ]

# Make a list of the elements in lst that are positive:
[ x for x in lst if x>0 ]

# The last two are examples of _filter_ operations:
# Making a list with elements selected from another list by some condition.
# (We could also use the `filter` function, which we'll see later.)


## More complex operations

# List comprehensions can easily describe a mix of map and filter operations.

# Create a list of the squares of the odd numbers in lst:
[ x**2 for x in lst if x%2==1 ]

# A table of people names, weights and heights:
people = [("John", 64.5, 1.757),
        ("Berta", 64.0, 1.612),
        ("Maria", 45.1, 1.715),
        ("Andy", 98.3, 1.81),
        ("Lisa", 46.8, 1.622),
        ("Kelly", 83.2, 1.78)]

# Extract a list of people that weigh more than 70 kg: 
[ p for p in people if p[1]>70 ]

# A list of the names of people that are shorter than 1.7m:
[ p[0] for p in people if p[2]<1.7 ]

# The same thing, but using tuple assignment in the for clause:
[ name for name,weight,height in people if height<1.7 ]
    # Quite readable, right?

# A list of (name,weight) pairs for people shorter than 1.7m:
[ (name,weight) for name,weight,height in people if height<1.7 ]

# A list of classifications for people:
[ 'heavy' if weight>70 else 'light'  for name,weight,height in people ]
    # Note that `x if c else y` is a conditional expression,
    # not a part of the list comprehension syntax!

# A list of football teams in a tournment:
teams = ['A', 'B', 'C', 'D']

# List of all possible pairs of teams:
[ (x, y) for x in teams for y in teams ]

# Oops! We want only pairs of DISTINCT teams:
[ (x, y) for x in teams for y in teams if x!=y ]


## Problem: find a list of Pytagorean triples.

# (See definition in http://mathworld.wolfram.com/PythagoreanTriple.html)

# First try:
[ (a,b,c) for a in range(20)    # Yes, we may split into different lines!
          for b in range(20)
          for c in range(35)
          if a**2+b**2==c**2 ]

# Oops! We should start with 1:
[ (a,b,c) for a in range(1,20)
          for b in range(1,20)
          for c in range(1,35)
          if a**2+b**2==c**2 ]

# But (3,4,5) and (4,3,5) are identical triples...
# We could eliminate duplicates by requiring the extra condition a<b,
# but we can avoid them altogheter by choosing proper ranges:
[ (a,b,c) for a in range(1,20)
          for b in range(a+1,20)    # we want only b > a!
          for c in range(b+1,a+b)   # we know a < b < c < a+b (why?)
          if a**2+b**2==c**2 ]

# How would we do this in the "traditional" way?
p = []
for a in range(1,20):
    for b in range(a+1,20):
        for c in range(b+1,a+b):
            if a**2+b**2==c**2:
                p.append( (a,b,c) )
p


## And now for something completely different:®

# Try to understand what we're doing below.
d = {"as": "the", "os": "the", "e": "and", "praia": "beach"}
t = "as armas e os barões assinalados que da ocidental praia lusitana"
t.split()
[ d[w] for w in t.split() ]     # OOPS! Error!
[ d[w] for w in t.split() if w in d ]   # Not quite what we intended, yet...
[ d[w] if w in d else w  for w in t.split() ]   # Ah! We're almost there...
l2 = [ d[w] if w in d else w for w in t.split() ]
" ".join(l2)                    # Finally!
# Another way to do it:
" ".join( [ d.get(w, w) for w in t.split() ] )  # Nice!

# I hope you had fun.  I did.

