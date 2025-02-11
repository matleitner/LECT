# Example: counting words in a text file

# Start with an empty dict:
dc = {}

c = 0
with open("pg3333.txt") as f:
    for line in f:
        for w in line.split():
            w = w.lower()
            if w in dc:
                dc[w] += 1
            else:
                dc[w] = 1

#print(dc["armas"])
#print(dc["amor"])

for pal, cont in dc.items():
    print(pal, cont)

