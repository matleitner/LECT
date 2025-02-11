# Compute trigonometric functions with Taylor series.
# See: https://en.wikipedia.org/wiki/Taylor_series#Trigonometric_functions

import math

def sin_a(x):
    """Return approximation to sin x."""
    # sin x = x - x³/3! + x⁵/5! - x⁷/7! + ...
    sum=0
    sum_anterior = -1
    i = 0
    #for i in range(5):
    while sum != sum_anterior:
        sum_anterior = sum 
        sum = sum + (-1)**(i)/math.factorial(2*i+1) * x**(2*i+1)
        i+=1
    
    return sum

# Constants
PI2 = math.pi * 0.5         # pi/2


def sin(x):
    """Return the sine of x."""
    # Use periodicity and simmetries of the sine function to reduce the
    # computation of sin x to the computation of sin r with 0 <= r <= pi/2.
    
    # Reduce
    n, r = divmod(x, PI2)    # x = n*pi/2 + r
    q = int(n) % 4           # quadrant

    # Approximate & Reconstruct
    if q == 0:
        s = sin_a(r)
    elif q == 1:
        s = sin_a(PI2 - r)
    elif q == 2:
        s = -sin_a(r)
    else: # q == 3
        s = -sin_a(r)
    return s


def main():
    # Prints the values of sine computed by my function and Python's math.sin.
    print(f"{'angle':>5s} {'mysin':>19s} {'pysin':>19s} {'error':>19s}")
    for angle in range(0, 90+1, 15):  # angle in degrees
        x = math.radians(angle)
        mysin = sin(x, pysin)
        pysin = math.sin(x)
        error = mysin - pysin
        print(f"{angle:5d} {mysin:19.16f} {pysin:19.16f} {error:19.16f}")


if __name__ == "__main__":
    main()

