def piramide(n):
    if n==1:
        return 1
    if n == 0:
        return 0
    
    return piramide(n-1)+4*n


print(piramide())
