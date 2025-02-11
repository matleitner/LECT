
#FUNCIONA TUDO KATCHAU

def inputFloatList():
    lista = []
    c = input("pappapa\n")
    while c != "":
        lista.append(float(c))
        c = input("pappapa\n")
    return lista

list_char = inputFloatList()

def countLower(lista, v):
    lista2 = []
    for i in lista:
        if i<v:
            lista2.append(i)
    return lista2


print(list_char)
def minmax(lista):
    min = lista[0]
    max = lista[0]
    for i in lista:
        if i<min:
            min = i
        if i>max:
            max = i
    return max,min   
maximo, minimo = minmax(list_char)

media = (maximo + minimo)/2
listabadass = countLower(list_char,media)
print(len(listabadass))