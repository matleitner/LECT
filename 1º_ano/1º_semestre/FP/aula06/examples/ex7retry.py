# Example: Catching exceptions and retrying
#
# JMR 2019

# inputInt1 is a function that asks for an integer.
# This version will crash if you input a word (not an integer)
def inputInt1(prompt):
    n = int(input(prompt))
    return n

# inputInt2 is robust version: it retries until you input an integer!
def inputInt2(prompt):
    while True:
        try:
            x = int(input(prompt))
            break
        except:
            print("Enter an int, please!")
    return x


def main():
    print("What happens if you input a word?")
    x = inputInt1("x? ")
    print("x:", x)
    
    print("What happens if you input a word?")
    y = inputInt2("y? ")
    print("y:", y)

main()

