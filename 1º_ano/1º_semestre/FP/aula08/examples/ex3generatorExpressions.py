# Example: Generator expressions.
# These examples are meant to be executed in Python INTERACTIVE MODE.
# Copy and execute each line and check the results.

# JMR, 2018

lst = [7, 3, 14, 15, 2, 2]

# Generator expressions are like list comprehensions, but with () instead of []
g = (100+x for x in lst)
type(g)
g           # Does not expand values...
list( g )   # But we can convert to another type for that.
list( g )   # Once expanded, the generator is exhausted
            # (It's like reaching the end of a file.)

# That's why we don't generally store generator expressions in variables.
# They'd be useful just once.

# Generator expressions are very useful to pass as arguments to functions that
# process collections, such as sum, max, min, all, any.

sum( [x for x in lst if x<10] ) 
    # This creates a new list in memory, only to compute its sum.

sum( (x for x in lst if x<10) )
    # Using a generator expression saves memory space, and returns the same.

sum( x for x in lst if x<10 )
    # Parentheses may be ommited if the generator is the sole argument!

[ x%3==0 for x in lst ]
all( x%3==0 for x in lst )
any( x%3==0 for x in lst )

# We can use generator expressions and convert to other collection types:
tuple( 100+x for x in lst )
