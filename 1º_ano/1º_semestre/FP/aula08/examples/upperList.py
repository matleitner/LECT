def upperList(lst):
    lst2 = []
    for v in lst:
        v2 = v.upper()
        lst2.append(v2)
    return lst2


lst = ["ana", "john", "marie"]
lst2 =  upperList(lst)
print(lst2)

