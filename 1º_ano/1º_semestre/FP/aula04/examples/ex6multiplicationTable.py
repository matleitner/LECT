# Print a multiplication table like this:
#   1 x 1  =   1
#   1 x 2  =   2
#   ...
#  10 x 10 = 100
#
# JMR 2019

# This is a SOLUTION to a CodeCheck problem proposed in tp04-xxxx.pdf.
# TRY to do that first, then compare the solutions.
# CodeCheck: https://codecheck.io/files/22101220409b8l9hmb75ub9iy8abhcop62v

def main():
    for a in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]:
        for b in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]:
            print("{} x {} = {}".format(a, b, a*b))

# Make the program print an empty line after each group of ten.
# Also, use format specifiers to align the numbers.

if __name__ == "__main__":
    main()

