# 1. 

## a) 

NumPeixes;
NumArpoes;
PeixeFrente;

## b) 

PeixeNaFrente
AcertoComArpao

## c)
|  Situação |  Acção  | Actualização | 
| --- |  ---  |  ---|
| PeixeNaFrente ^ numArpoes > 0 & num_peixes < 20 & ~fish_hit| Disparar | NumArpoes -= 1 | 
| AcertoComArpao ^ PeixeNaoCheio  | Agarrar  | NumPeixe += 1; NumArpoes+=1|  
| NaoTemArpoes |Reabastecer  | NumArpoes = 10 |
|PeixeCheio |Descarregar  | NumPeixes = 0 |
| ~PeixeNaFrente |Vaguear  | | 




# III

# 1

## a) Todos em Oxford são espertos 

$$ \forall x ( Oxford(x) → espertos(x) ) $$

## b) Alguém em Oxford é esperto
$$ \exists x (Oxford(x) \land espertos(x)) $$

## c) Existe uma pessoa que gosta de toda a gente

$$ \exists x ( Pessoa(x) \land (\forall y Pessoa(y) → gosta(x,y)) )

## d) Só um aluno chumbou a História. 

$$ \exists x (Aluno(x) \land ChumbouHistoria(x) \land (\forall y Aluno(y) \land ChumbouHistoria(y)) → y = x) $$ 

## e) Nem todos os estudantes se inscreveram simultaneamente a Introdução à Inteligência Artificial e Sistemas de Operação.

$$ \exists x Estudante(x) \land \not (Inscrever(x, IA) \land Inscrever(x,SO())) $$  

## f) Só um aluno chumbou a História e a Biologia.

$$ \exists x ((Aluno(x) \land (Chumbou(x,Historia) \land Chumbou(x,Biologia) \land \forall y (Aluno(y) \land (Chumbou(y,Historia) \land Chumbou(y,Biologia) )) → y = x )$$ 

## g) A melhor nota a História foi mais elevada do que a melhor nota a Biologia.

$$ \exists x \exists n_1 (Nota(x,Historia, n_1)) \land \forall y \forall n_2 (Nota(y, Biologia, n_2)) → n_1 > n_2 $$ 

## h) Todos os Portistas gostam do Pinto da Costa.

$$ \forall x (Portista(x) → Gostar(x, Pinto da Costa)) $$

## i) Existe um Sportinguista que gosta de todos os Benfiquistas que não são espertos

$$ \exists x (Sportinguista(x) \land (\forall y Benfiquista(y) \land Espertos(y))) → Gostar(x, y) $$

## j) Existe um Barbeiro que barbeia toda a gente menos ele próprio.

$$ \exists x (Barbeiro(x) \land \not Barbeia(x,x) \land \forall y (y != x → Barbeira(x,y)))$$ 


# IV

## 1

## a)

Não é admissível, porque existem nós cuja heuristica é maior do que o custo minímo até à solução, por exemplo o nó F h(x) = 10 h*(x) = 3 + 1 +4 = 8 heuristica deveria ser 8, o G → h(x) = 8, h*(x) = 7 a heuristica deveria ser 7. E h(x) = 7 h*(x) = 6, h(x) deveria ser 6

## b)
Nó/h(x)/ g(x)/ f(x)
F/10/0/10 
C/3/3/6, H/1/5/6, G/8/3/11
^                   
B/2/1+3/6, D/4/2+3/9, E/7/1+3/11
^
A/0/4+4/8 (Solução)


do H/1/5/6 → I/4/5/9 Solução

## c) 

N-1 / X

9-1 / 2 = 4

## d) 

(B^(alpha+1) - 1) / (B - 1) = N

B^4 - 1 = 9 *(B - 1) 

B^4 - 1 = 9B - 9 
B^4 - 9B = -8
1 - 9 = -8


# 6.

Robot (subtype)-> Maquinas
.   .       .    
|st  \st     \st 
legs  wheels  tracked 
        .
         \ (member)
 3 ---- nauthilus 
(num wheels)



# 10 


## a) 

Adjacent(s1,s2)
Tank(State)
LoadedBarrel(B, x)
BarrelState(B,State)
BarrelAt(s)
RobotAt(s)


