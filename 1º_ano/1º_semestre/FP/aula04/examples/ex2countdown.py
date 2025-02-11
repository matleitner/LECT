# Example:
# Write a function that counts down from N and then prints "Go!".
# Write both a recursive version and an iterative version.
# JMR 2018

# Recursive version
def countdownR(n):
    if n > 0:
        print(n)
        countdownR(n - 1)
    else:
        print("Go!")

# Iterative version
def countdown(n):
    while n > 0:
        print(n)
        n = n - 1     
    print("Go!")

def main():
    # Test both:
    countdownR(5)
    countdown(3)

# Call
main()

