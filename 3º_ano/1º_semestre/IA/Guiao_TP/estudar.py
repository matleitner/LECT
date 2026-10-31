def interpretacoes(lista):
    numTuples = len(lista)
    if(lista == []):
        return [[]] 
    first, rest = lista[0], interpretacoes(lista[1:])
    resultado = []
    for r in rest:
        resultado.append([(first, True)] + r)
        resultado.append([(first, False)] + r)

    return resultado  

print(interpretacoes(["a","b"]))
# "a" "b"
# "b"
# []
#
# 

def g(x):
    if x == []:
        return [[]]
    y = g(x[1:])

    return y + [[x[0]] + z for z in y]

    
print(g([1,2,3]))
