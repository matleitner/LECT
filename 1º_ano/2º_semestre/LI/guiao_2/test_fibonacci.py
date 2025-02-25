import pytest 
from fibonacci import fibonacci
import random 
def test_inferior_1():
    print("Testa comportamento para n<1")
    assert fibonacci(-1) == []
    assert fibonacci(0) == [0]


def test_positivo():
    n = random.randint(2,101)
    assert len(fibonacci(n))== n+1 