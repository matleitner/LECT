# Example: A solution to the "Towers of Hanoi" puzzle.
# JMR@ua.pt 2018

from traced import traced

def show():
    """Mostra o estado das 3 torres."""
    print("A", A)
    print("B", B)
    print("C", C)
    print("--------")
    # Como usamos variáveis globais, esta função fica simples.

#@traced
def move1(x, y):
    """Move 1 disco da torre x para a torre y."""
    d = x.pop()
    y.append(d)
    show()

#@traced
def moveN(n, x, y, z):
    """Move n discos de x para z, através de y."""
    if n > 0:
        moveN(n-1, x, z, y) # move n-1 discos de x para y, através de z
        move1(x, z)         # move 1 disco de x para z
        moveN(n-1, y, x, z) # move n-1 discos de y para z, através de x
    

# Neste programa usamos três listas para representar as torres.
# Initial condition of the puzzle:
A = [4, 3, 2, 1]    # Pode experimentar com mais discos.
B = []
C = []
show()

moveN(len(A), A, B, C)

