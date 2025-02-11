# Example: traversing lists
# jmr 2018

fruits = ['banana', 'pear', 'orange']

print("Traversing the items (index not needed)")
for f in fruits:
    print(f)

print("Traversing the items and counting")
i = 0
for f in fruits:
    print(i, f)
    i += 1

print("Traversing using the index")
i = 0
while i < len(fruits):
    print(i, fruits[i])
    i += 1

print("Traversing using the index with a for loop")
for i in range(len(fruits)):
    print(i, fruits[i])

print("Traversing using enumerate")
for i, f in enumerate(fruits):
    print(i, f)

