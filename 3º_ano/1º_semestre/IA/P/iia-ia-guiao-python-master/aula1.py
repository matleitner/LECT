# Exercicio 1.1
def comprimento(lista):
    if lista == []:
        return 0
    return 1 + comprimento(lista[1:])


# Exercicio 1.2
def soma(lista):
    if not lista:
        return 0
    return lista[0] + soma(lista[1:])


# Exercicio 1.3
def existe(lista, elem):
    if lista == []:
        return False
    if lista[0] == elem:
        return True

    return False or existe(lista[1:], elem)


# Exercicio 1.4
def concat(l1, l2):

    if l1 == []:
        return l2

    return [l1[0]] + concat(l1[1:], l2)


# Exercicio 1.5
def inverte(lista):
    if lista == []:
        return []
    return [lista[-1]] + inverte(lista[:-1])


# Exercicio 1.6
def capicua(lista):
    if len(lista) == 1 or lista == []:
        return True

    if lista[0] != lista[-1]:
        return False

    return True and capicua(lista[1:-1])


# Exercicio 1.7
def concat_listas(lista):
    if lista == []:
        return []

    return concat(lista[0], concat_listas(lista[1:]))


# Exercicio 1.8
def substitui(lista, original, novo):
    if lista == []:
        return []
    if lista[0] == original:
        return [novo] + substitui(lista[1:], original, novo)

    return [lista[0]] + substitui(lista[1:], original, novo)


# Exercicio 1.9
def fusao_ordenada(lista1, lista2):
    if lista1 == []:
        return lista2

    if lista2 == []:
        return lista1

    if lista1[0] <= lista2[0]:
        return [lista1[0]] + fusao_ordenada(lista1[1:], lista2)

    return [lista2[0]] + fusao_ordenada(lista1, lista2[1:])


# Exercicio 1.10
def lista_subconjuntos(lista):

    if lista == []:
        return [[]]

    return lista_subconjuntos(lista[1:]) + [
        [lista[0]] + sub for sub in lista_subconjuntos(lista[1:])
    ]


# Exercicio 2.1
def separar(lista):
    pass


# Exercicio 2.2
def remove_e_conta(lista, elem):

    pass


# Exercicio 3.1
def cabeca(lista):
    pass


# Exercicio 3.2
def cauda(lista):
    pass


# Exercicio 3.3
def juntar(l1, l2):
    pass


# Exercicio 3.4
def menor(lista):
    pass


# Exercicio 3.6
def max_min(lista):
    pass
