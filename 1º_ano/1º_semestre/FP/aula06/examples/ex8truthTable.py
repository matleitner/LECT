# Example: writing a table to a file.
# This program produces the truth table for the boolean expression
# ((A and B) or C).
# The table is written as a tab-separated .csv file.

# We used `print` with options `sep` and `file`.
# A solution using `.write` and `.format` is in comments.

# JMR 2018

vals = [False, True]

with open("truthTable.csv", "w") as f:
    print("A", "B", "C", "A and B or C", sep="\t", file=f)
    #f.write("{}\t{}\t{}\t{}\n".format("A", "B", "C", "A ^ B v C"))
    for A in vals:
        for B in vals:
            for C in vals:
                print(A, B, C, A and B or C, sep="\t", file=f)
                #f.write("{}\t{}\t{}\t{}\n".format(A, B, C, A and B or C)) 

