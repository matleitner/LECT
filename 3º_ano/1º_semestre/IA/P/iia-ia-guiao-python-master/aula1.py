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
    primeiro = lista[0]
    restantes = lista[1:]

    subconjuntos_do_resto = lista_subconjuntos(restantes)

    comb_com_o_primeiro = [[primeiro] + sub for sub in lista_subconjuntos(lista[1:])]

    return subconjuntos_do_resto + comb_com_o_primeiro


# Exercicio 2.1
def separar(lista):
    if lista == []:
        return [], []

    primeiro_par = lista[0]

    lista1, lista2 = separar(lista[1:])

    return ([primeiro_par[0]] + lista1, [primeiro_par[1]] + lista2)


# Exercicio 2.2
def remove_e_conta(lista, elem):
    if lista == []:
        return ([], 0)
    if lista[0] == elem:
        lista_1, num = remove_e_conta(lista[1:], elem)
        return lista_1, 1 + num

    lista_1, num = remove_e_conta(lista[1:], elem)

    return [lista[0]] + lista_1, 0 + num


# Exercicio 3.1
def cabeca(lista):
    if lista == []:
        return None
    return lista[0]


# Exercicio 3.2
def cauda(lista):
    if lista == []:
        return None

    return lista[-1]


# Exercicio 3.3
def juntar(l1, l2):
    if len(l1) != len(l2):
        return None
    if l1 == []:
        return []

    primeiroPar = l1[0], l2[0]

    return [primeiroPar] + juntar(l1[1:], l2[1:])


# Exercicio 3.4
def menor(lista):
    if lista == []:
        return None
    if len(lista) == 1:
        return lista[0]
    menor_do_resto = menor(lista[1:])
    return lista[0] if lista[0]< menor_do_resto else menor_do_resto

    




# Exercicio 3.6
def max_min(lista):
    if lista == []:
        return None
    if len(lista) == 1:
        return lista[0], lista[0]
    maior_resto, menor_resto = max_min(lista[1:])
    if lista[0] > maior_resto:
            novo_maior = lista[0]
    else:
            novo_maior = maior_resto
    
        # Descobrimos o verdadeiro menor
    if lista[0] < menor_resto:
            novo_menor = lista[0]
    else:
            novo_menor = menor_resto
    
    return novo_maior, novo_menor

    
