# Example:
# A function that recursively adds all numbers found inside a given object.
#
# JMR 2022

from traced import traced


@traced
def sumAllNumbers(obj):
    """Sum all the numbers contained in the given object."""

    tot = 0
    # If obj is a number, use it.
    if isinstance(obj, (int, float, complex)):
        tot = obj
    # If obj is a sequence or set, call recursively for each element and add.
    elif isinstance(obj, (list, tuple, set, frozenset)): # (str not needed)
        for x in obj:
            tot += sumAllNumbers(x)
    # If obj is a dictionary, call recursively for each of its keys and values.
    elif isinstance(obj, dict):
        for k, x in obj.items():
            tot += sumAllNumbers(k) + sumAllNumbers(x)
    # Other types are ignored.

    return tot


def main():
    obj1 = ["one", 2, ["three", 4, [5, "six"]]]
    obj2 = [1, "a", ("b", [{"c", "d", 2}, 3, (4, "e")], "f")]
    obj3 = {"a": 1, "b": ["c", "d"], (2, ("x", 3)): obj1, 77: 88}

    print( sumAllNumbers(8.2) )
    print( sumAllNumbers(obj1) )
    print( sumAllNumbers(obj2) )
    print( sumAllNumbers(obj3) )


if __name__ == "__main__":
    main()

