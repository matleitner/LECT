# Example: More on lambda expressions and higher-level functions.
# Copy each statement and execute in INTERACTIVE mode!

# JMR 2018

# Lambda expressions may be used to define simple functions:
tri = lambda n: n*(n+1)//2
    # The lambda expression creates a function,
    # and we assign it to the tri variable.

# Now we can call the function in tri, just like any other function:
tri(3)  # 6
tri(4)  # 10

# What type of value is in tri?
type(tri)
    # lambda expressions create functions

# Functions may be stored in variables just like any other object:
P = print
P("Hi there!", "I am a", type(P))

# Another little function:
f = lambda x,y: 10*x+y
f(4, 2)     # 42
f(1, 5)     # 15


# The lambda expression creates a function with no name.
# Check this out:
(lambda x: x**2)(6)     # 36
(lambda x: x**2)(9)     # 81



# Functions may be passed as arguments to other functions.
# This is useful to make more general functions.

# This function gets input and makes sure it contains only letters:
def inputLetters(msg):
    while True:
        s = input(msg)
        if s.isalpha(): return s       # s is valid => return
        print("Not valid!")

v = inputLetters("Letters? ")   # Try inputting "s0m3th1ng"

# Generalize the function to validate any other condition:
def inputValidate(msg, cond):      # cond should be a boolean function
    while True:
        s = input(msg)
        if cond(s): return s       # s is valid => return
        print("Not valid!")

# Using same function to get different kinds of strings:
v = inputValidate("Letters? ", cond=str.isalpha)
v = inputValidate("Digits? ", cond=str.isdigit)

# This checks if s is something like "+352-234-82382771"
def isPhone(s):
    return len(s)>0 and s[0] in "0123456789+" and \
            all( c in "0123456789-" for c in s[1:] )

v = inputValidate("Phone number? ", cond=isPhone)

# Exercise: fill in the ... with a lambda expression to validate a percentage!
v = inputValidate("Percentage? ", cond=...)


# Functions may also create and return other functions.
def generateMultiplierBy(factor):
    return lambda x: factor*x

doubleOf = generateMultiplierBy(2)
tripleOf = generateMultiplierBy(3)

doubleOf(7)
doubleOf(5.5)
tripleOf(10)
tripleOf(12)

