lista = [1,2,3,4]

print(list(map(lambda x: x*x, lista)))
print(list(filter(lambda x: x%2==0, lista)))



#def reduce(f,lista, neutro):
#    if lista == []:
#        return neutro;
#
#    return f(reduzir(f,lista[1:], neutro), lista[0])



lista2 = [ x**2 for x in lista if x%2==0 ]
print(lista2)
