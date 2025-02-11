import math 
colunas = float(input('Número de colunas?\n'))
diametro= float((input('Diametro?\n')))
altura =  float((input('Altura?\n')))

def arealateral(r,h):
    Area=colunas*(2*math.pi*r*h)
    return Area

#lata_pequena = 0.75
#lata_grande = 3 
#1 litro dá para 8m^2
#3 latas peq custam mais que 1 lata grande 4 latas peq. menos que 1 grande 
def num_latas(a):
    litros_tinta = a/8
    num_lata_grande= litros_tinta//3
    num_lata_peq=math.ceil((litros_tinta%3)/0.75)
    return num_lata_grande, num_lata_peq
print(arealateral(diametro/2,altura))
print(num_latas(arealateral(diametro/2,altura)))
