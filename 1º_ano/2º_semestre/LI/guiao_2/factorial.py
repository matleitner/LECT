def factorial(x):
    if x == 0:
        return 1
    if x == 1:
        return 1
    reg = 1
    
    while x>1:
        reg*=x
        x-=1
    return reg
def main():
    print( factorial(-1))

if __name__ == "__main__":
    main()