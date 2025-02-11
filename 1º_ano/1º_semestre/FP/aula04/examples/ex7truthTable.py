# Example: Print truth tables of boolean expressions
# Consider three independent boolean variables A, B and C
# and two dependent variables X and Y given by:
#   X = (A and not B) or C
#   Y = A and (not B or C)
# Print the truth tables for these variables and check if X <=> Y.
# 
# JMR 2019

boolValues = [False, True]
#boolValues = [0, 1]         # another way to represent logical values...

def main():
    print("{}\t{}\t{}\t{}\t{}".format("A","B","C","X","Y"))
    for A in boolValues:
        for B in boolValues:
            for C in boolValues:
                X = (A and not B) or C
                Y = A and (not B or C)
                print("{}\t{}\t{}\t{}\t{}".format(A,B,C,X,Y))

    # Use format specifiers to align the columns

if __name__ == "__main__":
    main()

