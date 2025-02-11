# Example: An efficient recursive sorting algorithm.
# This is a kind of Quick Sort (but not in-place).
#
# JMR 2020

from traced import traced


#@traced    # (uncomment to trace function calls)
def qsorted(lst):
    """Return a sorted version of lst (without changing lst)."""
    if len(lst) <= 1:   # no need to sort
        return lst[:]   # just return a copy
    # Select Pivot element (might be randomly selected)
    P = lst[0]
    # Define 3 lists for elements <P, =P or >P
    L1, L2, L3 = [], [], []
    for x in lst:
        # Select which list to append x to
        if x < P:
            L = L1
        elif x > P:
            L = L3
        else:
            L = L2
        # Append x to the correct list
        L.append(x)
    # Now, sort L1 and L3 and concatenate all three
    return qsorted(L1) + L2 + qsorted(L3)

# Chalenge: Make a generic version with a key= keyword argument.


# Test
def main():
    #lst0 = [7, 4, 5, 9, 1, 3, 8, 2, 6]
    lst0 = [5, 7, 2, 9, 23, 3, 43, 34, 9, 13]

    lst2 = qsorted(lst0)
    print(lst2)
    assert lst2 == sorted(lst0)


if __name__ == "__main__":
    main()

