# Example functions created in TP lesson #3.
# jmr@ua.pt 2018

## Example 1: A simple function to compute a square number

def sqr(x):
    y = x**2
    return y

print("3 ao quadrado é", sqr(3))


## Example 2: A BAD example of using a global variable

def power(x):
    y = x**exp      # exp is not local! 
    # x and y are local because they are assigned values inside the function!
    return y

# define some global variables
x = 99
y = 33
exp = 3
z = 10 + power(2)
print("z:", z)     # 18 (= 10 + 2**3)
print(x, y)        # still 99 33  (x and y inside power are local)
exp = 10
z = power(2)
print("z:", z)     # 1024 (2**10)
print(x, y)        # still 99 33  (x and y inside power are local)


## Example 3: A nicer way would use exp as parameter

def power(x, exp):
    return x**exp

print(power(2, 3))
print(power(2, 10))


## Example 4: Functions can take any type of argument
def fullname(first, last):
    first = first.title()   # title makes the first letter uppercase!
    last = last.title()
    return first + " " + last

print( fullname("maria", "costa") )
print( fullname("fernando", "pessoa") )


## Example 5: Functions can return several values (as a tuple)
def sec2hms(secs):
    """Convert seconds to h, m, s."""
    s = secs % 60
    mins = secs // 60
    m = mins % 60
    h = mins // 60
    return (h, m, s)

h, m, s = sec2hms(7531)
print(h, m, s)      # 2 5 31

