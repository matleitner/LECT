# Respostas do Guião 1 Prático

# Parte 1
# Initial Network setup + VRRP

## a)

### Routing table

R1 - C-192.0.13.0/24
	 C-192.0.12.0/24
	 C-192.1.1.0/24


etc para todos os routers

## b)

Falha porque a única gateway do PC1 foi desligada, PC1 só consegue enviar para essa gateway.

## c)

no GNS

## d)

gns

## e)

VRRP cria uma gateway virtual e anúncia várias vezes que existe e funciona por prioridades por exemplo neste caso R1 é o que tem mais prioridade por isso PC1 vai mandar para esse router, caso ele deixe de existir ele envia para o R2 que tem VRRP configurado.

## f) 

Automáticamente R2 fica como master virtual default gateway

## g)

## h) 



# Parte 2 
# RIP (IPv4)

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

# Parte 3
# OSPF (IPv4)
# Link-State (Dijkstra)

## 3.a. 
Aparece um **O** para a rede 24 é Transit

## 3.b. 
O caminho através da rede 192.1.1.0 não existe é Stub 

R1- 

O     192.0.24.0/24 [110/2] via 192.0.12.2, 00:00:41, FastEthernet0/0


R2-

O     192.0.13.0/24 [110/2] via 192.0.12.1, 00:00:41, FastEthernet0/0


## 3.b. IPv4

Ver no packote
IP destino → 224.0.0.5

## 3.c. 

Hello Packet, Periodicidade de 10 seg.

## 3.d.
Router 1 ID: 192.1.1.1 

Router 2 ID: 192.1.1.2

Backup Designated Router: 192.0.12.1

Designated Router: 192.0.12.2

### Nota: Router ID: é configurado ou maior endereço IP 

## 3.e. 

R1→ sh ip ospf interface brief
Interface    PID   Area            IP Address/Mask    Cost  State Nbrs F/C
Fa1/0        1     0               192.1.1.1/24       1     DR    0/0
Fa0/1        1     0               192.0.13.1/24      1     DR    0/0
Fa0/0        1     0               192.0.12.1/24      1     DROTH 0/1

R1→ sh ip ospf neighbor 

Neighbor ID     Pri   State           Dead Time   Address         Interface
192.1.1.2         1   FULL/DR         00:00:33    192.0.12.2      FastEthernet0/0


R2→ sh ip ospf interface b
Interface    PID   Area            IP Address/Mask    Cost  State Nbrs F/C
Fa1/0        1     0               192.1.1.2/24       1     DR    0/0
Fa0/1        1     0               192.0.24.2/24      1     DR    0/0
Fa0/0        1     0               192.0.12.2/24      1     DR    1/1


R2→ sh ip ospf neighbor

Neighbor ID     Pri   State           Dead Time   Address         Interface
192.1.1.1         1   FULL/BDR        00:00:33    192.0.12.1      FastEthernet0/0



## 3.f.

### a)

2 Router Link States 1 Net Link State
### b)

...

### c) 

advertiser → quem enviou a informação 


### d) 

1 

## 3.g. 

## 3.h.

## 3.i 

Os pacotes Update 

___

# Notas da aula 

### Descoberta de topologia (flooding enundação) → Base de Dados → Dijsktra → Tabela de Encaminhamento 
## LSR link state Request 

Quando um dos routers percebe que não tem uma informação de outro ele pede um Request para por na base de dados. 

## Pacotes OSPF Update 
Router LSA Link state Advertisment

"Olha eu sou o router X e estou ligado a Y redes"

Network LSA

"Existe uma rede X que tem Y routers ligados toma nota"

## Hello Pacotes

Para manter a informação de cada router


## Rotas default 

E2 - External 2 (custo fixo) 

E1 - External 1 (custo depende do caminho até router 5 neste caso + custo ir para fora default é 1)

Se tiver mais que um router de saida, configuro E1 para melhor gestão de tráfego 


# Para ver o custo da rota externa: ` show ip ospf database external `



# Parte 4 
# OSPF em IPv6 
