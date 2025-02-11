# Example: Processing strings
# JMR 2018

# How many letters does s contain?
def countLetters(s):
    n = 0
    for c in s:
        if c.isalpha():
            n += 1
    return n

# How many digits does s contain?
def countDigits(s):
    n = 0
    for c in s:
        if c.isdigit():
            n += 1
    return n

# Return a string containing the digits in string s.
# (The result string is built by successive concatenation.)
def filterDigits(s):
    t = ""
    for c in s:
        if c.isdigit():
            t += c
    return t


# Testing:
print(countLetters("AA-12-56")) #-> 2
print(countDigits("AA-12-56"))  #-> 4

r = filterDigits("AA-12-56")    #-> "1256"
print(r)

