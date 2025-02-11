def squareList(lst):
    lst2 = []
    for v in lst:
        v2 = v**2
        lst2.append(v2)
    return lst2


lst = [1, 2, 3]
lst2 =  squareList(lst)
print(lst2)

