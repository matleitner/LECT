# Example: sequential and binary searching.

# JMR 2018

# Search x in list lst, sequentially.
# Return index if found, else None.
def seqSearch(lst, x):
    """Return k such that x == lst[k]. (Or None if no such k.)"""
    for k in range(len(lst)):
        if x == lst[k]: return k
    return None

# Same thing, but using a binary search.
# The lst must be sorted for this to work!
def binSearchExact(lst, x):
    """Find k such that x == lst[k]. (Or None if no such k.)"""
    a = 0
    b = len(lst)
    while a<b:
        k = (a+b)//2
        if x > lst[k]:
            a = k+1
        elif x < lst[k]:
            b = k
        else:
            return k
    return None

# An optimized binary search.
# Returns an index k such that:
#   all elements in lst[:k] are < x and
#   all elements in lst[k:] are >= x.
# This is equivalent to bisect.bisect_left(lst, x).
def binSearch(lst, x):
    a = 0
    b = len(lst)
    while a<b:
        k = (a+b)//2
        if x > lst[k]:
            a = k+1
        else:
            b = k
    return a

# This uses the optimized version and checks if x is found.
def binSearchExact2(lst, x):
    """Find k such that x == lst[k]. (Or None if no such k.)"""
    # This is generally faster than binSearchExact!
    k = binSearch(lst, x)
    if k == len(lst) or x != lst[k]:
        return None
    return k



import time

def main():

    # Load a file containing words into a list:
    with open("/usr/share/dict/words", encoding="utf8") as f:
        words = [w.strip() for w in f]
    
    # Check that the words are sorted:
    print( all( words[i]<=words[i+1] for i in range(len(words)-1) ) )   # True

    print(len(words))
    print(words[10000:10005])  # just checking a few words

    x = input("word to search? ")

    t = time.perf_counter()
    found = x in words
    t = time.perf_counter() - t
    print("{!r} in words == {} in {} ms".format(x, found, t*1000))

    if found:
        t = time.perf_counter()
        k = words.index(x)           # ValueError if x not in words!
        t = time.perf_counter() - t
        word = words[k]
        print("words.index({!r}) == {} -> {}  in {} ms".format(x, k, word, t*1000))
    
    t = time.perf_counter()
    k = seqSearch(words, x)
    t = time.perf_counter() - t
    word = words[k] if k!=None else "----"
    print("seqSearch(words, {!r}) == {} -> {}  in {} ms".format(x, k, word, t*1000))

    t = time.perf_counter()
    k = binSearch(words, x)
    t = time.perf_counter() - t
    word = words[k] if k!=None else "----"
    print("binSearch(words, {!r}) == {} -> {}  in {} ms".format(x, k, word, t*1000))


if __name__ == '__main__':      # If called as a script, run main()
    main()

