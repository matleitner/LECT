# Respostas do Guião 1 Prático

---

# Parte 1

---

# Initial Network setup + VRRP
## Virtual Router Redundancy Protocol


All routers of the cluster send VRRP announcement messages to a standard
defined multicast address:
-  IPv4: 224.0.0.18
-  IPv6: FF02::12
- The “best router” (the one with the highest VRRP priority or the highest IP address, if the priority is the same) acts as master and keeps sending the VRRP messages (default advertisement interval = 1 second)
-  If the master fails (i.e., if it does not send VRRP messages for 3 seconds), the “best router” among the remaining ones becomes the master.

--- 

## a)

### Routing table

R1 - C-192.0.13.0/24
	 C-192.0.12.0/24
	 C-192.1.1.0/24


etc para todos os routers

Não existem rotas remotas porque não há protocolo de routing ativo.

## b)

Falha porque a única gateway do PC1 foi desligada, PC1 só consegue enviar para essa gateway.

PC1 não consegue encaminhar tráfego para fora da rede local


## c)

O gateway volta a estar disponível

A conectividade é restaurada


## d)

RRP cria um gateway virtual (192.1.1.254) partilhado por R1 e R2.

- R1 → prioridade 120 → Master
- R2 → prioridade 100 → Backup

PC1 passa a usar 192.1.1.254 como gateway

## e)

VRRP cria uma gateway virtual e os routers anúncia várias vezes para 204.0.0.18 que existe e funciona por prioridades por exemplo neste caso R1 é o que tem mais prioridade por isso PC1 vai mandar para esse router, caso ele deixe de existir ele envia para o R2 que tem VRRP configurado.

## f) 

(Devia ser o f1/0 do R1)

Automáticamente R2 fica como master virtual default gateway

## g)
Será de novo o R1 como master virtual default gateway porque tem mais prioriddade.

## h) 
(Enunciado mal feito por causa das prioridades) 
Mas acho que o que seria pretendido era visualizar que embora se desligue a default gateway o PC1 tem sempre um "backup" nunca perde a conectividade. 
```
setup & VRRP

R1>
conf t
int f1/0
ip address 192.1.1.1 255.255.255.0
no shut
int f0/0
ip address 192.0.12.1 255.255.255.0
no shut
int f0/1
ip address 192.0.13.1 255.255.255.0
no shut
end
wr

conf t
int f1/0
vrrp 1 ip 192.1.1.254
vrrp 1 priority 120
end
wr

R2>
conf t
int f1/0
ip address 192.1.1.2 255.255.255.0
no shut
int f0/0
ip address 192.0.12.2 255.255.255.0
no shut
int f0/1
ip address 192.0.24.2 255.255.255.0
no shut
end 
wr


conf t
int f1/0
vrrp 1 ip 192.1.1.254
end
wr

R3>
conf t
int f1/0
ip address 192.0.35.3 255.255.255.0
no shut
int f0/0
ip address 192.0.34.3 255.255.255.0
no shut
int f0/1
ip address 192.0.13.3 255.255.255.0
no shut
end
wr

R4>

conf t
int f1/0
ip address 192.0.46.4 255.255.255.0
no shut
int f0/0
ip address 192.0.34.4 255.255.255.0
no shut
int f0/1
ip address 192.0.24.4 255.255.255.0
no shut
end
wr

R5>

conf t
int f1/0
ip address 192.0.35.5 255.255.255.0
no shut
int f0/0
ip address 192.0.56.5 255.255.255.0
no shut
int f0/1
ip address 192.3.3.5 255.255.255.0
no shut
int f1/1
ip address 192.2.2.5 255.255.255.0
no shut
end
wr

R6>

conf t
int f1/0
ip address 192.0.46.6 255.255.255.0
no shut
int f0/0
ip address 192.0.56.6 255.255.255.0
no shut
end
wr


PC1>ip 192.1.1.100/24 192.1.1.2
save

PC2>ip 192.2.2.2/24 192.2.2.5
save

PC3>ip 192.3.3.3/24 192.2.2.5
save



```
---

# Parte 2 
---

# RIP (IPv4)
## Routing Information Protocol

### Algoritmo distance vector (distribuido) Bellman-Ford

- Each router maintains a list of known IP networks and, for each network, an estimation of the cost to reach it – this is called a distance vector.
-  Each router periodically sends to its neighbour routers its own distance vector (partially or complete).
-  Each router uses the distance vector received from its neighbours to
update its own distance vector
---

### The path cost from a router to a remote IP network destination is given by the number of intermediate routers along the path.

- Maximum cost is 15.
- A cost of 16 is considered infinite (i.e., an unreachable destination).


### For each remote IP network in the distance vector, the router adds anentry towards each neighbour router providing the lowest cost


## 2.a. 
R1:

	  192.0.12.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.0.12.0/24 is directly connected, FastEthernet0/0

	  192.0.13.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.0.13.0/24 is directly connected, FastEthernet0/1

R     192.0.24.0/24 [120/1] via 192.1.1.2, 00:00:22, FastEthernet1/0
                    [120/1] via 192.0.12.2, 00:00:00, FastEthernet0/0
      192.1.1.0/24 is variably subnetted, 2 subnets, 2 masks
C        192.1.1.0/24 is directly connected, FastEthernet1/0


R2: 

C        192.0.12.0/24 is directly connected, FastEthernet0/0

R     192.0.13.0/24 [120/1] via 192.1.1.1, 00:00:05, FastEthernet1/0

                    [120/1] via 192.0.12.1, 00:00:07, FastEthernet0/0

	  192.0.24.0/24 is variably subnetted, 2 subnets, 2 masks


C        192.0.24.0/24 is directly connected, FastEthernet0/1
      
	  192.1.1.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.1.1.0/24 is directly connected, FastEthernet1/0
 
Em ambos foi adicionado uma rede por RIP, que é a rede que não é diretamente conectada.

192.1.1.0/24 is a transit network 

## 2.b. 

UDP -> 520 para transmitir e emitir
<br>
multicast 224.0.0.9 (todos os routers que tiverem o RIP configurado) (all rip routers)


## 2.c.

RIP responses

T = 30s


## 2.d. 

with Split-Horizon, mecanismo para o router não incluir todas as redes, mas ele apenas envia as redes que não passam pela ligação, Split-horizon impede que um router anuncie uma rota pela interface por onde a aprendeu, evitando loops de routing.


## 2.e.
R1:

	  192.0.12.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.0.12.0/24 is directly connected, FastEthernet0/0

      192.0.13.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.0.13.0/24 is directly connected, FastEthernet0/1

R     192.0.24.0/24 [120/1] via 192.0.12.2, 00:00:25, FastEthernet0/0

      192.1.1.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.1.1.0/24 is directly connected, FastEthernet1/0


R2:

	  192.0.12.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.0.12.0/24 is directly connected, FastEthernet0/0

R     192.0.13.0/24 [120/1] via 192.0.12.1, 00:00:17, FastEthernet0/0

      192.0.24.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.0.24.0/24 is directly connected, FastEthernet0/1

	  192.1.1.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.1.1.0/24 is directly connected, FastEthernet1/0

--- 

Tornamos as interfaces da network 192.1.1.0/24 como passivas e os routers já não enviam packtes RIP para esse lado. O caminho através da 192.1.1.0 já não existe agora é stub. Não é usada para ir para outros sitios.

## 2.f.
Não há pacotes RIP na rede 192.1.1.0/24 porque essa rede é stub.

A métrica enviada nos pacotes justifica-se, a saida de cada router é 1, a rede que um router sabe (**neste caso**) encontra-se ligada diretamente, ao router ou seja a métrica é 1. Isso contribui para que o vetor distância ser 1.


## 2.g.

A network de Sw2 e Sw3 não aparece porque no router5 não foi incluída na configuração de RIPv2 

## 2.h.

Foi adicionado uma rota default para o próximo salto em direção ao router 5


### Código usado:

```

R1>conf t
router rip
version 2
network 192.1.1.0
network 192.0.12.0
network 192.0.13.0
end
write


conf t
router rip
passive-interface f1/0
end 

write

R2>conf t
router rip
version 2
network 192.1.1.0
network 192.0.12.0
network 192.0.24.0
end
write


conf t
router rip
passive-interface f1/0
end 

write

R3> conf t
router rip
version 2
network 192.0.35.0
network 192.0.13.0
network 192.0.34.0
end
write

R4>
conf t
router rip
version 2
network 192.0.34.0
network 192.0.46.0
network 192.0.24.0
end
write

R5>conf t
router rip
version 2
network 192.0.35.0
network 192.0.56.0
network 192.2.2.0
network 192.3.3.0
end
write

R6>conf t
router rip
version 2
network 192.0.46.0
network 192.0.56.0
end
write

conf t
router rip 
default-information originate
end 
wr

```
---

# Parte 3
---

# OSPF (IPv4)

# Link-State routing protocol (Dijkstra)

- Each router sends its part of the network topology to all routers in the form of Link-State Advertisements (LSA) LSAs are sent by their responsible routers through flooding to all other routers.


- The router uses its LSDB (Link-State Data Base) to calculate the minimum cost routing paths from it towards each remote IP network (using Dijkstra’s algorithm).


- The router adds to its IP routing table an entry towards each next-hop (i.e., neighbour) router providing the minimum cost.




## 3.a. 
Aparece um **O** para a rede 24

192.1.1.0 é Transit

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

DBD

LSR

LSU

LSAck

## 3.d.
Router 1 ID: 192.1.1.1 

Router 2 ID: 192.1.1.2

Backup Designated Router: 192.0.12.1

Designated Router: 192.0.12.2

### Nota: Router ID: é configurado ou maior endereço IP 

## 3.e. 
```
R1→ sh ip ospf interface brief

Interface    PID   Area            IP Address/Mask    Cost  State Nbrs F/C
Fa1/0        1     0               192.1.1.1/24       1     DR    0/0
Fa0/1        1     0               192.0.13.1/24      1     DR    0/0
Fa0/0        1     0               192.0.12.1/24      1     DROTH 0/1

R1→ sh ip ospf neighbor 

Neighbor ID     Pri   State           Dead Time   Address         Interface

192.1.1.2         1   FULL/DR         00:00:33    192.0.12.2      FastEthernet0/0

---

R2→ sh ip ospf interface b

Interface    PID   Area            IP Address/Mask    Cost  State Nbrs F/C
Fa1/0        1     0               192.1.1.2/24       1     DR    0/0
Fa0/1        1     0               192.0.24.2/24      1     DR    0/0
Fa0/0        1     0               192.0.12.2/24      1     DR    1/1


R2→ sh ip ospf neighbor

Neighbor ID     Pri   State           Dead Time   Address         Interface

192.1.1.1         1   FULL/BDR        00:00:33    192.0.12.1      FastEthernet0/0
```

## 3.f.

### a)

2 Router Link States 1 Net Link State
### b)

Representa topologia R1-R2

### c) 

advertiser → quem enviou a informação 


### d) 

1 

## 3.g. 

Caminhos escolhidos através do algoritmo de menor custo Dijkstra.

## 3.h.
Redes Sw2/Sw3 não são anúnciadas por R5

## 3.i 

LSU, recalculo SPF, atualização da routing table

## 3.j
Falha de link, LSA atualizados, rotas recalculadas


## 3.k

Default route, tipo E2, custo fixo

## 3.l
Novo LSA, Type 5 - AS External LSA

## 3.m 
Atualiza custo externo 

## 3.n
LSA atualizado com novo custo

## 3.o 
E1, custo inclui caminho interno + externo

## 3.p
```
R1#show ip ospf database

            OSPF Router with ID (192.1.1.1) (Process ID 1)

						Router Link States (Area 0)

Link ID         ADV Router      Age         Seq#       Checksum Link count
192.0.35.3      192.0.35.3      353         0x80000003 0x00F018 3
192.0.46.4      192.0.46.4      335         0x80000003 0x007748 3
192.0.56.6      192.0.56.6      284         0x80000003 0x003FFE 2
192.1.1.1       192.1.1.1       417         0x80000003 0x001F6C 3
192.1.1.2       192.1.1.2       397         0x80000003 0x00610F 3
192.3.3.5       192.3.3.5       207         0x80000004 0x009A20 2

		Net Link States (Area 0)

Link ID         ADV Router      Age         Seq#       Checksum
192.0.12.2      192.1.1.2       428         0x80000001 0x0035E8
192.0.13.1      192.1.1.1       417         0x80000001 0x00FB01
192.0.24.2      192.1.1.2       397         0x80000001 0x001AC8
192.0.34.4      192.0.46.4      358         0x80000001 0x005C2A
192.0.35.3      192.0.35.3      358         0x80000001 0x00DFD9
192.0.46.4      192.0.46.4      335         0x80000001 0x00144E
192.0.56.5      192.3.3.5       283         0x80000001 0x00495C

                Type-5 AS External Link States

Link ID         ADV Router      Age         Seq#       Checksum Tag
0.0.0.0         192.3.3.5       62          0x80000002 0x003BA8 1
```
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


## a)
Apenas aparecem redes diretamente conectadas

## b) 
As interfaces têm IPv6 Global e IPv6 link-local

## c) soma dos custos das interfaces (cada saída é 1) 
OSPFv3 adiciona rotas, baseadas em custo

Next-hop, endereço link-local

## d) nova entrada: OE2 External type 2 

## e) LSA

## f)
Confirmações 
- 3 router LSAs
```
R1#show ipv6 ospf database router

  OSPFv3 Router with ID (192.1.1.1) (Process ID 1)

		Router Link States (Area 0)
#### 1ª confirmação ####
  LS age: 197
  Options: (V6-Bit, E-Bit, R-bit, DC-Bit)
  LS Type: Router Links
  Link State ID: 0
  Advertising Router: 192.0.35.3
  LS Seq Number: 80000001
  Checksum: 0x64FE
  Length: 56
  Number of Links: 2

    Link connected to: a Transit Network
      Link Metric: 1
      Local Interface ID: 5
      Neighbor (DR) Interface ID: 5
      Neighbor (DR) Router ID: 192.3.3.5

    Link connected to: a Transit Network
      Link Metric: 1
      Local Interface ID: 4
      Neighbor (DR) Interface ID: 4
      Neighbor (DR) Router ID: 192.1.1.1
### 2ª ###

  LS age: 196
  Options: (V6-Bit, E-Bit, R-bit, DC-Bit)
  LS Type: Router Links
  Link State ID: 0
  Advertising Router: 192.1.1.1
  LS Seq Number: 80000002
  Checksum: 0x5717
  Length: 40
  Number of Links: 1

    Link connected to: a Transit Network
      Link Metric: 1
      Local Interface ID: 4
      Neighbor (DR) Interface ID: 4
      Neighbor (DR) Router ID: 192.1.1.1

### 3ª ###

  LS age: 198
  Options: (V6-Bit, E-Bit, R-bit, DC-Bit)
  LS Type: Router Links
  Link State ID: 0
  Advertising Router: 192.3.3.5
  LS Seq Number: 80000002
  Checksum: 0xEB70
  Length: 40
  Number of Links: 1

    Link connected to: a Transit Network
      Link Metric: 1
      Local Interface ID: 5
      Neighbor (DR) Interface ID: 5
      Neighbor (DR) Router ID: 192.3.3.5


```


- 2 Net LSAs
```
            OSPFv3 Router with ID (192.1.1.1) (Process ID 1)

		Net Link States (Area 0)
### 1 ###
  LS age: 430
  Options: (V6-Bit, E-Bit, R-bit, DC-Bit)
  LS Type: Network Links
  Link State ID: 4 (Interface ID of Designated Router)
  Advertising Router: 192.1.1.1
  LS Seq Number: 80000001
  Checksum: 0x880E
  Length: 32
	Attached Router: 192.1.1.1
	Attached Router: 192.0.35.3
### 2 ###
  LS age: 432
  Options: (V6-Bit, E-Bit, R-bit, DC-Bit)
  LS Type: Network Links
  Link State ID: 5 (Interface ID of Designated Router)
  Advertising Router: 192.3.3.5
  LS Seq Number: 80000001
  Checksum: 0x92F2
  Length: 32
        Attached Router: 192.3.3.5
	Attached Router: 192.0.35.3
```
- 3 Prefix LSAs
```

            OSPFv3 Router with ID (192.1.1.1) (Process ID 1)

		Intra Area Prefix Link States (Area 0)

### 1 ###
  Routing Bit Set on this LSA
  LS age: 465
  LS Type: Intra-Area-Prefix-LSA
  Link State ID: 0
  Advertising Router: 192.1.1.1
  LS Seq Number: 80000003
  Checksum: 0x28F0
  Length: 44
  Referenced LSA Type: 2001
  Referenced Link State ID: 0
  Referenced Advertising Router: 192.1.1.1
  Number of Prefixes: 1
  Prefix Address: 2001:1:1::
  Prefix Length: 64, Options: None, Metric: 1

### 2 ###
  Routing Bit Set on this LSA
  LS age: 465
  LS Type: Intra-Area-Prefix-LSA
  Link State ID: 4096
  Advertising Router: 192.1.1.1
  LS Seq Number: 80000001
  Checksum: 0x33C2
  Length: 44
  Referenced LSA Type: 2002
  Referenced Link State ID: 4
  Referenced Advertising Router: 192.1.1.1
  Number of Prefixes: 1
  Prefix Address: 2001:0:13::
  Prefix Length: 64, Options: None, Metric: 0

### 3 ###
  Routing Bit Set on this LSA
  LS age: 467
  LS Type: Intra-Area-Prefix-LSA
  Link State ID: 5120
  Advertising Router: 192.3.3.5
  LS Seq Number: 80000001
  Checksum: 0x7846
  Length: 44
  Referenced LSA Type: 2002
  Referenced Link State ID: 5
  Referenced Advertising Router: 192.3.3.5
  Number of Prefixes: 1
  Prefix Address: 2001:0:35::
  Prefix Length: 64, Options: None, Metric: 0
```

- 1 External LSA
```
show ipv6 ospf database external

            OSPFv3 Router with ID (192.1.1.1) (Process ID 1)
```


# Parte 5

# OSPF e RIP a comunicarem-se

## a)  

R1 e R2 so conhecem o domínio RIP, e os R4, R5, R6 só conhecem o domínio OSPF

## b)
Redistribuição RIP → OSPF:

Cria rotas externas (E2)
## c)
Redistribuição OSPF → RIP:

redes aparecem como métrica 1

## d) 

Cria uma Default route

## e) 
Melhor solução é d. é mais simples e mais escalável.

