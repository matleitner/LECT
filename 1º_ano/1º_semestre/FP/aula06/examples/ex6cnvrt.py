# Example: Using exceptions to check type convertions
# JMR 2018

# This function works like int(x), but if x cannot be converted,
# returns None instead of raising an exception.
def intOrNone(x):
    try:
        r = int(x)
    except ValueError:
        r = None
    return r

def testIntOrNone():
    # Using assert for testing:
    assert intOrNone("123") == 123
    assert intOrNone("one") == None
    assert intOrNone("1.2") == None
    print("intOrNone passed all tests")

# This function works like int(input(.)),
# but repeats until the user inputs a proper int value.
def inputInt(prompt):
    while True:
        try:
            x = int(input(prompt))
            break
        except ValueError:
            print("ERRO! Tem de ser inteiro!" )
    return x

# This function returns True iff s can be converted to a float without error.
def isFloat(s):
    try:
        float(s)    # try converting (and discard result)
        r = True
    except ValueError:
        r = False
    return r

def testIsFloat():
    # Test isFloat:
    assert isFloat("12.3") == True
    assert isFloat("-6.7e-4") == True
    assert isFloat("2019") == True
    assert isFloat("dez") == False
    assert isFloat("MCMLXXII") == False
    print("isFloat passed all tests")


def main():
    # An example of using the isFloat function
    while True:
        s = input("Can you enter a real number? ")
        if isFloat(s): break
        print("Nope! That's not a real number!")
    x = float(s)        # we're sure this works!
    print("OK. Here is your number plus 1000:", x+1000)


# PROG
age = inputInt("age? ")
print(age)

#testIntOrNone()
#testIsFloat()
#main()

print("FIM")

