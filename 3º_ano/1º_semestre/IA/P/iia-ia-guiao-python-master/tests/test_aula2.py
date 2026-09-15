import mock
import types
import aula2
from aula2 import *

#Exercicio 4.1
def test_par_impar():
    assert isinstance(impar, types.FunctionType)
    assert impar(3) 
    assert not impar(4)

#Exercicio 4.2
def test_positivo():
    assert isinstance(positivo, types.FunctionType)
    assert positivo(3) 
    assert not positivo(-4)

#Exercicio 4.3
def test_comparar_modulo():
    assert isinstance(comparar_modulo, types.FunctionType)
    assert not comparar_modulo(-4, 2)
    assert comparar_modulo(3, -4) 
    
#Exercicio 4.4
def test_cart2pol():
    assert isinstance(cart2pol, types.FunctionType)
    assert cart2pol(0, 1) == (1.0, 1.5707963267948966)

#Exercicio 4.5
def test_ex5():
    assert isinstance(ex5, types.FunctionType)
    t = ex5(lambda x,y: x+y, lambda x,y: x*y, lambda x,y: x < y)
    assert isinstance(t, types.FunctionType)
    assert t(1,2,3) == True 

#Exercicio 4.6
@mock.patch('aula2.quantificador_universal', side_effect = aula2.quantificador_universal)
def test_quantificador_universal(mock_qt_uni):
    assert mock_qt_uni([11,12,13,14], lambda n: n > 10)

#Exercicio 4.8
@mock.patch('aula2.subconjunto', side_effect = aula2.subconjunto)
def test_subconjunto(mock_subconjunto):
    assert mock_subconjunto([11,12,13,14], [11,12,13,14,15,16])
    assert mock_subconjunto([11,12,13,14], [10,11,12,13,14])
    assert mock_subconjunto([11,12,13,14], [10,11,12,13,14,15])
    assert not mock_subconjunto([11,12,33,14], [10,11,12,13,14,15])


#Exercicio 4.9
@mock.patch('aula2.menor_ordem', side_effect = aula2.menor_ordem)
def test_menor_ordem(mock_menor_ordem):
    assert mock_menor_ordem([1,-1,4,0], lambda x,y: x < y) == -1
    assert mock_menor_ordem([1,-1,4,0], lambda x,y: x > y) == 4

#Exercicio 4.10
@mock.patch('aula2.menor_e_resto_ordem', side_effect = aula2.menor_e_resto_ordem)
def test_menor_e_resto_ordem(mock_menor_e_resto_ordem):
    m, r =  mock_menor_e_resto_ordem([1,-1,4,0], lambda x, y: x < y) 
    assert m == -1
    assert sorted(r) == sorted([1,4,0])
    m2, r2 = mock_menor_e_resto_ordem([1,-1,4,0], lambda x, y: x > y) 
    assert m2 == 4
    assert sorted(r2) == sorted([1,-1,0])

#Exercicio 5.2a
@mock.patch('aula2.ordenar_seleccao', side_effect = aula2.ordenar_seleccao)
def test_ordenar_seleccao(mock_ordenar):
    assert mock_ordenar([1,-1,4,0], lambda x, y: x < y) == [-1, 0, 1, 4]
    assert mock_ordenar([1,-1,4,0], lambda x, y: x > y) == [4, 1, 0, -1]
