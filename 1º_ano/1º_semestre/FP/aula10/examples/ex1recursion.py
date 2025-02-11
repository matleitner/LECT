# Example: How recursive functions work.

from traced import traced

# A non-recursive function:
#@traced
def sumsq(lst):
    s = 0
    for x in lst:
        s += x**2
    return s

# A recursive function that is equivalent to sumsq.
#@traced            #(C)
def sumsqR(lst):
    #print("sumsqR({})".format(lst))        #(A)
    s = 0
    if len(lst) > 0:
        sq0 = lst[0]**2
        s = sq0 + sumsqR(lst[1:])
    #print("sumsqR({})->{}".format(lst, s)) #(B)
    return s

# Testing both functions:
print( sumsq([1, 2, 3]) )
print( sumsqR([1, 2, 3]) )

# To see how sumsqR works, uncomment the print statements (A) and (B).
# This will show: (A) each time the function is CALLED, and
# (B) each time the function RETURNS.

# A better way to do this:
# Remove (or comment) the print statements (A) and (B),
# and uncomment line (C).
# The @traced annotation modifies the function to do the prints automatically.
# (That annotation is implemented in module traced.py.)

