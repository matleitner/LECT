# Example functions created in TP lesson #3.
# jmr@ua.pt 2018

# A function to print a message twice
def printTwice(msg):
    print(msg)
    print(msg)

# A function to print a message three times
def print3times(msg):
    print(msg)          # print once
    printTwice(msg)     # call previous fcn to print twice more...

# A function to print a message four times
def print4times(msg):
    print(msg)
    print3times(msg)

# A generalization to print a message any number of times
def printNtimes(msg, n):
    if n > 0:
        print(msg)
        printNtimes(msg, n-1)   # It calls itself! Cool!


printNtimes("bla", 3)
