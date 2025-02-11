# Example: Using dictionary comprehensions.
# These examples are meant to be executed in Python INTERACTIVE MODE.
# Copy and execute each line and check the results.

# JMR, 2018

# A list of numbers, defined by extension:
lst = [2, 5, -3, 1, -2, 4]

# A list of strings:
args = ['apple', 'dell', 'ibm', 'hp', 'sun']

# We can define dictionaries by comprehension:
{ x:len(x) for x in args }
    # Do you see how the syntax differs from a list comprehension?

# Another example:
{ (a,b):c for a in range(1,20)
          for b in range(a+1,20)
          for c in range(b+1,a+b)
          if a**2+b**2==c**2 }
