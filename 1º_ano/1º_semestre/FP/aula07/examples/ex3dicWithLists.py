

# This counts words in a file:
c = {}
with open("pg3333.txt") as f:
    for line in f:
        words = line.strip().split()
        for w in words:
            w = w.lower()
            cw = c.get(w, 0)    # get the counter for w, or 0
            c[w] = cw + 1
            
#print(c)

#for w in sorted(c.keys()):
#    print("{:20} {:3}".format(w, c[w]))


# Separate distinct words according to their first letter:
startingWith = {}
for w in sorted(c.keys()):
    start = w[0]                # take the first letter in w
    if start in startingWith:
        startingWith[start].append(w)   # append w to list of words
    else:
        startingWith[start] = [w]



#starting["a"] -> ["armas", "amor", ...]
print(startingWith["a"])
print(startingWith["z"])

