
# Responses to the Practical Guide 2 
# RIP 
Algoritmo distance vector (distribuido) Bellman-Ford


## 2.a. 
192.1.1.0/24 is a transit network 

## 2.b. 

UDP ->520 para transmitir e emitir
<br>
multicast 224.0.0.9 (todos os routers que tiverem o RIP configurado) (all rip routers)


## 2.c.

RIP responses

T = 30s


## 2.d. 

with Split-Horizon, mecanismo para o router não incluir todas as redes, mas ele apenas envia as redes que não passam pela ligação

## 2.e.

Tornamos as interfaces da network 192.1.1.0/24 como passivas e os routers já não enviam packtes RIP para esse lado. O caminho através da 192.1.1.0 já não existe agora é stub. Não é usada para ir para outros sitios.

## 2.f.

## 2.g.

## 2.h.

Foi adicionado uma rota default para o próximo salto em direção ao router 5

# 3
# OSPF 
# Link-State (Dijkstra)

## 3.a. 
Aparece um **O** para a rede 24 é Transit

## 3.b. 
O caminho através da rede 192.1.1.0 não existe é Stub 

## 3.c. 



