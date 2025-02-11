# Example: a simple translator

# A dict with translations of Portuguese words to English:
d = {"as": "the", "os": "the", "e": "and", "praia": "beach"}

# Try: as armas e os barões assinalados que da ocidental praia lusitana
s = input("Texto? ")
t = ""
for w in s.split():
    if w in d:      # check if word w is a key in dictionary d
        w = d[w]
    t = t + " " + w

print(t)
