
def nextDay(y, m, d):
    assert dateIsValid(y, m, d)
    d += 1
    ...     # rest of solution here
    ...
    assert dateIsValid(y, m, d)
    return (y, m, d)
    
        
def testNextDay():
    assert nextDay(1920, 2, 28) == (1920, 2, 29)
    assert nextDay(1920, 2, 29) == (1920, 3, 1)
    assert nextDay(1920, 12, 31) == (1921, 1, 1)
    print("ALL OK!")


