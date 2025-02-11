# Approximating the value of PI/4 using the Leibniz formula.
# JMM 2019 
import math

# Calculates Pi using the Leibniz series for N items
def LeibnizPi(N):
    s = 0
    for n in range(N):
        v_n = (-1)**n / (2*n+1)
        s += v_n
    return 4*s

def main():
    # Prints the value of PI: a constant in math
    print("PI = ", math.pi)
    print()

    # Prints the header of the results table
    print("{:>8s} {:>12s} {:>12s}".format("N", "sum", "error"))
    print("-"*8, "-"*12, "-"*12)

    # Prints the values of the approximation of PI for 
    # N = [1, 10, 100, 1000, 10000, 100000, 1000000, 10000000]
    for exp in range(0, 8):
        num = 10**exp
        total = LeibnizPi(num)
        appError = abs(math.pi - total)
        print("{:8d}   {:.8f}   {:.8f}".format(num, total, appError))

if __name__ == "__main__":
    main()

