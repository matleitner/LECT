# Example: loops inside loops
# JMR 2018

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
def doSomething():
    for c in letters:
        for d in letters:
            print(c, d)

# What does this print? How many lines?
doSomething()

