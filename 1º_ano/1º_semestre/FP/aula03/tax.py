def tax(r):
    if r<=1000:
        res = 0.1*r
    elif 1000<r<=2000:
        res = 0.2*r -100
    elif 2000<r:
        res =  0.3*r-300
    else:
        exit(1)
    return res
rui = float(input("Insira numero"))



y = tax(rui)
print(y)