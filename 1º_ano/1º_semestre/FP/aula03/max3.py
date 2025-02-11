def max2(a,b):
    if a>b:
        return a
    else:
        return b 
    
def max3(a,b,c):
    a = max2(a,b)
    if a>c:
        return a 
    else: 
        return c
print(max3(1313123133,123,122222))