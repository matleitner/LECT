#~ Example: a function to read a list (using BAD programming practices)
#~ SM 2019

#~ Write a function that prompts the user for a sequence of numbers and
#~ RETURNS them in a LIST. To finish the sequence, the user enters an 
#~ empty line.

#~ To test the function, write a program that reads two lists and prints
#~ them. The program should also use the function to read a few more 
#~ numbers into the first list and print it again.

#~ This example uses BAD PROGRAMMING PRACTICES: a global variable is used
#~ Therefore,
#~ => it is not clear which functions modify global objects!
#~ => it is not easy to process several lists!

#~ Note that it is not clear that this function modifies an existing list
def readlst():
    print("Insert numbers after '>' (empty line to quit)")
    while True:
        line = input("> ")
        if line=="": break
        lst.append(float(line))  # not clear which list the function is modifying 

print("\n\nTesting function readlst()")
print("Reading List A")
lst = []
readlst()     # it is not clear that lst is going to be modified by readlst()

print("\nReading List B")
#~ if we need to read more lists, first we have to copy the reference to lst
lstA = lst
lst = []        # and then to reset the reference lst to the empty list again
readlst()
lstB = lst 

print("lstA: ", lstA)
print("lstB: ", lstB)

print("\nInserting more numbers in List A")
lst = lstA    # Now, we need to have lst referencing lstA again...
readlst()
print("lstA: ", lstA)

#~ this is confusing, not pratical and it can generate semantic errors
#~ that may be very difficult to debug

