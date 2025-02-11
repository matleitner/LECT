# Example: finding and counting leap years
# JMR 2019, 2024

# This a SOLUTION to a CodeCheck problem proposed in tp04-xxxx.pdf.
# TRY to do that first, then compare the solutions.
# CodeCheck: https://codecheck.io/files/221012195892yicwdpq4toavxuffimd7p6p

def isLeapYear(year):
   return year%4 == 0 and year%100 != 0 or year%400 == 0


def printLeapYears(year1, year2):
   """Print all leap years in range [year1, year2[."""
   # Try to use a while loop!
   ano = year1
   while ano < year2:
      if isLeapYear(ano):
         print(ano)
      ano += 1


def numLeapYears(year1, year2):
   """Return the number of leap years in range [year1, year2[."""
   # Try to use a for loop!
   num = 0
   for ano in range(year1, year2):
      if isLeapYear(ano):
         num += 1
   return num


def nextLeapYear(year):
   """Return the first leap year after the given year."""
   # Which kind of loop is more appropriate?
   year += 1
   while not isLeapYear(year):
      year += 1
   return year
   # Alternative (no loop):
   # year = (year+4)//4 * 4     # next multiple of 4
   # return year if isLeapYear(year) else year+4


def listLeapYears(year1, year2):
   """Return a list of leap years in range [year1, year2[."""
   lst = []
   # To add a value to the list, use:
   # lst.append(value)
   # (We'll get back to lists later in the course.)
   for ano in range(year1, year2):
      if isLeapYear(ano):
         lst.append(ano)
   return lst


# MAIN PROGRAM:
def main():
   printLeapYears(1870, 1921)

   x = numLeapYears(1679, 2079)
   print("In [1679, 2079[ there are", x, "leap years")

   print(f"{nextLeapYear(2024) = }")  # 2028
   print(f"{nextLeapYear(1893) = }")  # 1896
   print(f"{nextLeapYear(1896) = }")  # 1904

   print(listLeapYears(1970, 2002))


if __name__ == "__main__":
   main()

