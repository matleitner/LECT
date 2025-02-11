def f1(a,b):
    print(a)
    print(b)
    c =a+b
    return c
def f2(k):
    s = 0
    for i in range(k):
        s+=1
    return s


x = int(input())
y = int(input())
z = f1(x,y)
print(z)
print(f2(z))
