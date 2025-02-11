# This program shows a table of the squares of four numbers.
# Modify the program to show the squares of 1..20.  Use the range function.
# Also, add a column to show 2**n.  Adjust the formatting.

print("{:>2s}\t {:>3s}\t {:>7s}\t".format("n", "n²", "2**n"))
for n in range(1,21):
    print("{:>2d}\t {:>3d}\t {:>7d}\t".format(n, n**2, 2**n))
