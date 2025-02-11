# Example:
# A function to check if a number is prime.
# JMR 2018

import math

def isPrime(n):
    r = int(math.sqrt(n) + 0.1)
    # r = n-1  OR  r = n//2  would work, but are less efficient
    d = 2
    while d <= r:
        if n % d == 0:
            return False
        d += 1      # after d=3 we could test only odd divisors...
    return True
    # isPrime(1) returns True, but should return False!  Fix it!

def main():
    # test all numbers from 1 to 39
    for n in range(1, 40):
        print(n, isPrime(n))

# call main function:
main()

