# Example: 
# Read numbers until a sentinel (an empty string), and return their sum.
# JMR 2018

# This a SOLUTION to a CodeCheck problem proposed in tp04-xxxx.pdf.
# TRY to do that first, then compare the solutions.
# CodeCheck: https://codecheck.io/files/221012201945qzz0zt3yx0jbwm581tn38sa

# This is a typical example of a "loop-and-a-half":
# a common situation where the exit condition
# should be tested in the middle of the loop body.

def inputTotal():
    tot = 0.0
    while True:
        s = input("valor? ")
        if s == "": break   # if empty line, stop repeating!
        v = float(s)
        tot = tot + v
    return tot

# MAIN PROGRAM
def main():
    tot = inputTotal()
    print(tot)

if __name__ == "__main__":
    main()

