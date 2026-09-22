from math import sqrt, atan2
from functools import reduce
#Exercicio 4.1
impar = lambda x: x % 2 != 0;

#Exercicio 4.2
positivo = lambda x: x > 0 

#Exercicio 4.3
comparar_modulo = lambda x,y: abs(x)>abs(y) 

#Exercicio 4.4
cart2pol = lambda x,y: (sqrt(x*x + y*y), atan2(y,x)) 

#Exercicio 4.5
def ex5(f,g,h):
    return  lambda x,y,z: f(g(x,y),h(y,z))

#Exercicio 4.6
def quantificador_universal(lista, f):

    return all(map(f,lista))

#Exercicio 4.8
def subconjunto(lista1, lista2):
    return  all(map(lambda x: x in lista2, lista1))
    
#Exercicio 4.9
def menor_ordem(lista, f):

    return reduce(lambda menor, atual: atual if f(atual, menor) else menor, lista)

#Exercicio 4.10
def menor_e_resto_ordem(lista, f):
    pass


#Exercicio 5.2
def ordenar_seleccao(lista, ordem):
    ...
