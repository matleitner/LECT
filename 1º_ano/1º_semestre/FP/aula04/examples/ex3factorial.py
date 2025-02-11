# Example: Write a function to compute the factorial of N.
# Do it with two kinds of loop.
# JMR 2019

def factorial(n):
    i = 1
    r = 1
    while i <= n:
        r = r * i
        i += 1
    return r

def factorialB(n):
    r = 1
    for i in range(1, n + 1):
        r = r * i
    return r

def main():
    print(factorial(4))
    print(factorialB(3))

main()

