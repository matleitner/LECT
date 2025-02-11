#~ Example: a function to read a list (using good programming practices)
#~ SM 2019

#~ Write a function that prompts the user for a sequence of numbers and
#~ RETURNS them in a LIST. To finish the sequence, the user enters an 
#~ empty line.

#~ To test the function, write a program that reads two lists and prints
#~ them. The program should also use the function to read a few more 
#~ numbers into the first list and print it again.

#~ -----------------------------------------------------------------
#~ One solution: to define a function that creates a new (empty) list,
#~ inserts the numbers and returns the list.
#~ Note: it does not allow to append numbers to an existing list, but
#~ you can concatenate lists.
def readlst():
    print("Insert numbers after '>' (empty line to quit)")
    lst = []
    while True:
        line = input("> ")
        if line=="": break
        lst.append(float(line))
    return lst

#~ Testing the function
print("Testing function readlst()")
print("Reading List A")
lstA = readlst()

print("\nReading List B")
lstB = readlst()

print("lstA: ", lstA)
print("lstB: ", lstB)

print("\nInserting more numbers in List A")
lstA = lstA + readlst()
print("lstA: ", lstA)


#~ -----------------------------------------------------------------
#~ Another solution: a function that appends numbers to an existing list
#~ Note: in this case you must create the list before calling the function
def readlst(lst):
    print("Insert numbers after '>' (empty line to quit)")
    while True:
        line = input("> ")
        if line=="": break
        lst.append(float(line))
    return lst   # return not required, but it may be helpfull (see below) 

#~ Testing the function
print("\n\nTesting function readlst(lst)")
print("Reading List A")
lstA = []
readlst(lstA)

print("\nReading List B")
lstB = readlst([])  # Because the function returns the list reference

print("lstA: ", lstA)
print("lstB: ", lstB)

print("\nInserting more numbers in List A")
readlst(lstA)
print("lstA: ", lstA)

