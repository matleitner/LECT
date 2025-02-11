
def primesUpTo(n):
    numbers = set(range(2,n+1))

    p=2
    while p**2 < n:
        if p  in numbers:
            numbers -= (set( range(p**2,n+1,p)))
        p+=1
        
    return numbers

def main():
    # Testing:
    s = primesUpTo(30)
    print(s)

    # Do some checks:
    assert primesUpTo(30) == {2,3,5,7,11,13,17,19,23,29}
    assert len(primesUpTo(1000)) == 168
    assert len(primesUpTo(7918)) == 999
    assert len(primesUpTo(7919)) == 1000
    print("All tests passed!")

if __name__ == "__main__":
    main()

