# This example shows assert statements used with 3 different purposes.

# Run the program to test the function.  All tests should pass.
# Then:
# - Try uncommenting #A and run.  (Then comment back.)
# - Try uncommenting #B and run.  (Then comment back.)
#
# - Try changing condition #C to  d**3 <= r.  This is a bug.
#   Which test fails?  Why did the postcondition not fail?  (Reset back)
#
# - Try commenting out (or removing) the if statement in #D.
#   Now the postcondition should fail.

#import pytest
import math


def factor(n):
    """Return a sorted list of prime factors of n."""
    # asserts for testing preconditions (the domain)
    assert type(n) == int , f"argument ({n=}) should be an integer"
    assert n >= 1         , f"argument ({n=}) should be positive"

    factors = []  # no factor found, so far
    ##HIDE
    r = n
    d = 2   # first divisor to try
    while d**2 <= r:        #C
        if r % d == 0:          # if d is a divisor of r
            factors.append(d)
            r = r // d          # the rest to factorize further
        else:
            d += 1              # try a larger divisor
    if r >= 1:              #D
        factors.append(r)
    ##SHOW ...
    
    # asserts for testing postconditions
    assert math.prod(factors) == n , f"product({factors}) should be {n}"
    return factors

    
def test_factor():
    for n in range(1, 100, 3):
        print(n, factor(n))

    # Try uncommenting each of these calls
    # factor(1.5)       #A
    # factor(0)         #B
    
    # asserts for testing the function
    assert factor(1) == [1]
    assert factor(4) == [2, 2]
    assert factor(6) == [2, 3]
    assert factor(2*3*7) == [2, 3, 7]
    assert factor(2*2*5*127) == [2, 2, 5, 127]
    assert factor(276381273819) == [3, 7, 89, 147876551]
    print("ALL OK")


if __name__ == "__main__":
    test_factor()

