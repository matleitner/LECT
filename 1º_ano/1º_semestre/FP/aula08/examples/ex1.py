# Some examples of list comprehensions
# JMR 2017, 2020

nums = [4, -5, 3, 7, 2, 3, 1]
args = ["apple", "dell", "ibm", "hp", "sun"]

print( [v**2 for v in nums] )

print( [a.upper() for a in args if len(a)>3] )

print( [a*n for a in args for n in nums if n>0] )

print( [(a,n) for a in args if a>"e" for n in nums if n>0] )

N = 20
print("Pytagorean triples with legs up to", N)
# See http://mathworld.wolfram.com/PythagoreanTriple.html
print( [(a,b,c) for a in range(1, N+1)
                for b in range(a, N+1)
                for c in range(b+1, a+b)
                if a**2 + b**2 == c**2] )

# What if we want only the _primitive_ triples?
# We need to make sure a and b are relatively prime.
import math
print("Primitive Pytagorean triples with legs up to", N)
print( [(a,b,c) for a in range(1, N+1)
                for b in range(a, N+1)
                for c in range(b+1, a+b)
                if a**2 + b**2 == c**2 and math.gcd(a, b) == 1] )

