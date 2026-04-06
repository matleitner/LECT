# Resolução de exercicios do guião 2
### Configuração da rede e VLANS:

```

PC1>ip 192.10.1.1/24 192.10.1.254
save

PC2>ip 192.20.1.1/24 192.20.1.254
save

PC3>ip 192.10.1.2/24 192.10.1.254
save

PC4>ip 192.20.1.2/24 192.20.1.254
save

PC5>ip 192.30.1.1/24 192.30.1.254
save

PC6>ip 192.10.1.3/24 192.10.1.254
save

PC7>ip 192.40.1.1/24 192.40.1.254
save


DIST1>
vlan database
vlan 10
vlan 20
vlan 30 
vlan 40
exit
conf t
int f1/0 
switchport mode access
switchport access vlan 10 


int f1/1
switchport mode access
switchport access vlan 20


int f1/15
switchport mode trunk
end 

wr

DIST2>
vlan database
vlan 10
vlan 20
vlan 30 
vlan 40
exit
conf t
int f1/0 
switchport mode access
switchport access vlan 10 


int f1/1
switchport mode access
switchport access vlan 20

int f1/2
switchport mode access
switchport access vlan 30


int f1/15
switchport mode trunk
end 
wr

DIST3>
vlan database
vlan 10
vlan 20
vlan 30 
vlan 40
exit
conf t
int f1/0 
switchport mode access
switchport access vlan 10 


int f1/1
switchport mode access
switchport access vlan 40


int f1/15
switchport mode trunk
end 

wr

CORE1>
vlan database
vlan 10
vlan 20
vlan 30 
vlan 40
exit
conf t

int range f1/0 - 2
switchport mode trunk
end 

wr


```

# 1. 

 
## a) 
```
VLAN Name                             Status    Ports
---- -------------------------------- --------- -------------------------------
1    default                          active    Fa1/0, Fa1/1, Fa1/2, Fa1/3
                                                Fa1/4, Fa1/5, Fa1/6, Fa1/7
                                                Fa1/8, Fa1/9, Fa1/10, Fa1/11
                                                Fa1/12, Fa1/13, Fa1/14, Fa1/15
1002 fddi-default                     active    
1003 token-ring-default               active    
1004 fddinet-default                  active    
1005 trnet-default                    active    

VLAN Type  SAID       MTU   Parent RingNo BridgeNo Stp  BrdgMode Trans1 Trans2
---- ----- ---------- ----- ------ ------ -------- ---- -------- ------ ------
1    enet  100001     1500  -      -      -        -    -        1002   1003
1002 fddi  101002     1500  -      -      -        -    -        1      1003
1003 tr    101003     1500  1005   0      -        -    srb      1      1002
1004 fdnet 101004     1500  -      -      1        ibm  -        0      0   
1005 trnet 101005     1500  -      -      1        ibm  -        0   
```

## b) 


| FROM | TO | Result of ping | Packet in CORE1-DIST1| Packets in CORE1-DIST3 |
|:---|:--:|:--:| :--:|---:|  
|PC1   | 192.10.1.2  | YES  | ICMP  ARP requests VLAN10 replies | ARP request    |    
|PC1   | 192.10.1.3  | YES ↑  | ↑  | ↑  | 
|PC1   | 192.10.1.10  |  NO (Host Not Reachable)  | | ARP Req  | ARP Req   |  
|PC1   | 192.20.1.2  | ↑  |  ↑    | ↑   |     
|PC2   | 192.20.1.2   | YES   |  ARP & ICMP req & reply   |  ARP Req  |     
|PC2   | 192.30.1.1   | NO ( Host Not Reachable)  |  ↑   |  ↑  |

---

# 2. Distributed Routing between VLANs 

Core vai tratar da vlan 10 e 20 porque essas vlans existem em mais que um dist. A Vlan 30 e 40 vão ser roteadas a partir do seu dist respetivamente.



## a)


### Core 1:

C    192.20.1.0/24 is directly connected, Vlan20
C    192.1.1.0/24 is directly connected, Vlan50
C    192.10.1.0/24 is directly connected, Vlan10

### Dist 1:

Não é router

### Dist 2:

C    192.30.1.0/24 is directly connected, Vlan30
C    192.1.1.0/24 is directly connected, Vlan50

### Dist 3:

C    192.1.1.0/24 is directly connected, Vlan50
C    192.40.1.0/24 is directly connected, Vlan40


Cada router só conhece a sua rede confugurada, porque ainda não tem prótocolo de routing.

## b) 

| VLAN | Connections / Scope | Why? |
| :--- | :--- | :--- |
| **VLAN 10** | PC1, PC3, PC6, DIST1, DIST2, DIST3, CORE1 | **End-to-End VLAN**: Embora o PC6 esteja no DIST3 e o PC1 no DIST1, partilham a mesma sub-rede e segmento Layer 2. Um broadcast viaja pelos trunks do CORE1 para todos os switches. |
| **VLAN 20** | PC2, PC4, DIST1, DIST2, CORE1 | **End-to-End (Restrita)**: Existe no DIST1 e DIST2. Como foi removida do trunk para o DIST3, o domínio de broadcast para aqui no CORE1 e não chega ao lado direito da topologia. |
| **VLAN 30** | PC5 e DIST2 (SVI 30) | **Local VLAN**: O DIST2 faz o roteamento local. Como a VLAN 30 foi removida do trunk para o CORE1, os broadcasts do PC5 ficam confinados ao DIST2. |
| **VLAN 40** | PC7 e DIST3 (SVI 40) | **Local VLAN**: Semelhante à VLAN 30, é roteada localmente pelo DIST3. Os broadcasts não saem das portas de acesso do DIST3 atribuídas a esta VLAN. |
| **VLAN 50** | CORE1, DIST2, DIST3 | **Transit VLAN**: Existe apenas nos links ponto-a-ponto entre os switches Layer 3 para permitir a troca de tabelas de routing (RIP) e o encaminhamento de pacotes entre redes. |

## c)

### Core 1:

C    192.20.1.0/24 is directly connected, Vlan20
R    192.30.1.0/24 [120/1] via 192.1.1.2, 00:00:21, Vlan50
C    192.1.1.0/24 is directly connected, Vlan50
C    192.10.1.0/24 is directly connected, Vlan10
R    192.40.1.0/24 [120/1] via 192.1.1.3, 00:00:06, Vlan50


### Dist 2

R    192.20.1.0/24 [120/1] via 192.1.1.1, 00:00:18, Vlan50
C    192.30.1.0/24 is directly connected, Vlan30
C    192.1.1.0/24 is directly connected, Vlan50
R    192.10.1.0/24 [120/1] via 192.1.1.1, 00:00:18, Vlan50
R    192.40.1.0/24 [120/1] via 192.1.1.3, 00:00:11, Vlan50


### Dist 3


R    192.20.1.0/24 [120/1] via 192.1.1.1, 00:00:10, Vlan50
R    192.30.1.0/24 [120/1] via 192.1.1.2, 00:00:22, Vlan50
C    192.1.1.0/24 is directly connected, Vlan50
R    192.10.1.0/24 [120/1] via 192.1.1.1, 00:00:10, Vlan50
C    192.40.1.0/24 is directly connected, Vlan40

## d)


| FROM | TO | Result of ping | Packet in CORE1-DIST1| Packets in CORE1-DIST3 |
|:---|:--:|:--:| :--:|---:|  
|PC1   | 192.20.1.1  | YES  | ICMP  ARP requests VLAN10 replies VLAN20 | ARP request    |    
|PC1   | 192.20.1.2  | YES  | TUDO  | IGUAL    | 
|PC1   | 192.30.1.1  |  YES  |  ↑   |  ↑  |  
|PC1   | 192.40.1.1  | YES   |  ↑    | ↑   |     
|PC1   | 192.1.1.2   | YES   |  ↑   |  ↑  |     
|PC7   | 192.10.1.3  | YES   |  TUDO   | ARP/ICMP Request e Reply|    
|PC7   | 192.1.1.3   |  YES  |  TUDO   | ↑  |


# 3. Redundant LANs with Spanning Tree 

## a)
Adicionar nos DISTs, f1/14 como trunk e nos CORES as VLANs e as interfaces a trunk.


## b)

``` 
DIST1>

VLAN1
  Bridge ID  Priority    32768
             Address     c203.2804.0000
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN10
  Bridge ID  Priority    32768
             Address     c203.2804.0001
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN20
  Bridge ID  Priority    32768
             Address     c203.2804.0002
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN30
  Bridge ID  Priority    32768
             Address     c203.2804.0003
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN40
  Bridge ID  Priority    32768
             Address     c203.2804.0004
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
############################################

DIST2>

VLAN1
  Bridge ID  Priority    32768
             Address     c204.2820.0000
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN10
  Bridge ID  Priority    32768
             Address     c204.2820.0001
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN20
  Bridge ID  Priority    32768
             Address     c204.2820.0002
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN30
  Bridge ID  Priority    32768
             Address     c204.2820.0003
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN40
  Bridge ID  Priority    32768
             Address     c204.2820.0004
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec

###########################################
DIST3>


VLAN1
  Bridge ID  Priority    32768
             Address     c205.283c.0000
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN10
  Bridge ID  Priority    32768
             Address     c205.283c.0001
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN20
  Bridge ID  Priority    32768
             Address     c205.283c.0003
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN30
  Bridge ID  Priority    32768
             Address     c205.283c.0004
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN40
  Bridge ID  Priority    32768
             Address     c205.283c.0002
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
#######################################

CORE1>

VLAN1
  Bridge ID  Priority    32768
             Address     c201.27cc.0000
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN10
  Bridge ID  Priority    32768
             Address     c201.27cc.0001
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN20
  Bridge ID  Priority    32768
             Address     c201.27cc.0002
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN30
  Bridge ID  Priority    32768
             Address     c201.27cc.0003
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN40
  Bridge ID  Priority    32768
             Address     c201.27cc.0004
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
######################################

CORE2>

VLAN1
  Bridge ID  Priority    32768
             Address     c202.27e8.0000
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN10
  Bridge ID  Priority    32768
             Address     c202.27e8.0001
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN20
  Bridge ID  Priority    32768
             Address     c202.27e8.0002
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN30
  Bridge ID  Priority    32768
             Address     c202.27e8.0003
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
VLAN40
  Bridge ID  Priority    32768
             Address     c202.27e8.0004
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec


```

Prioridade é a mesma logo o desempate é feito pelo mac address mais pequeno neste caso CORE1 c201....

## c)
Após a execução do comando show spanning-tree brief em todos os switches da topologia, verificou-se que os parâmetros configuráveis do Spanning Tree se encontram com os valores de fábrica (default).

A Bridge Priority em todas as VLANs e em todos os switches é de 32768. Relativamente às interfaces, sendo estas do tipo FastEthernet, apresentam um Port Cost de 19 e uma Port Priority de 128 (visível no prefixo do Port ID).

Como as prioridades são idênticas em todos os dispositivos, a eleição do Root Bridge foi decidida com base no menor endereço MAC, resultando na escolha do CORE1 como Root Bridge para todas as instâncias de VLAN analisadas.


---

			  **Root** Dist 1
			   /            \
			Core 1         Core 2
		     /   \
		  Dist2  Dist3
---

## d)
```
VLAN10
  Spanning tree enabled protocol ieee
  Root ID    Priority    32768
             Address     c201.27cc.0001
             Cost        19
             Port        56 (FastEthernet1/15)
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec

  Bridge ID  Priority    32768
             Address     c203.2804.0001
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec
             Aging Time 300

Interface                                   Designated
Name                 Port ID Prio Cost  Sts Cost  Bridge ID            Port ID
-------------------- ------- ---- ----- --- ----- -------------------- -------
FastEthernet1/0      128.41   128    19 FWD    19 32768 c203.2804.0001 128.41
FastEthernet1/14     128.55   128    19 BLK    19 32768 c202.27e8.0001 128.41
FastEthernet1/15     128.56   128    19 FWD     0 32768 c201.27cc.0001 128.41
```

### i)
Root ID ... Address c201.27cc.001


### ii) 
f1/0 Fowarding
f1/14 Blocking
f1/15 Fowarding

### iii) quem é o switch que envia para as redes

**Core 1**

f1/1 e f1/2 Designated Port

f1/15 route port

**Dist 1**

f1/15 DP

f1/14 DP

**Dist 2**

f1/15 RP 
f1/14 DP

**Dist 3**

f1/15 RP
f1/14 DP


### iv) 



----

A topologia final (spanning tree) é justificada pelos seguintes parâmetros:

-   Eleição do Root: Todos os switches têm a prioridade padrão (32768). O CORE1 foi eleito Root Bridge por possuir o menor MAC Address (c201...).

-    Custo do Caminho (Path Cost): Todas as interfaces são FastEthernet com um custo padrão de 19.

 -       O DIST1 tem custo 19 via f1/15 (direto ao CORE1).

 -      O DIST1 teria custo 38 via f1/14 (passando pelo CORE2: 19 + 19).

-   Seleção da Root Port: Como 19 < 38, a interface f1/15 é eleita como Root Port (FWD).

-   Prevenção de Loops: Para evitar o loop físico entre DIST1, CORE1 e CORE2, a interface f1/14 é colocada em estado de bloqueio (BLK). Ela é a porta com o ID mais alto ou o caminho mais longo para o Root nesta instância.
---

## e)

PVST+ (Per VLAN ST)
STP


## f) 

BLOCKING → LISTENING → LEARNING → FORWARDING 

As portas que antes estavam, BLK para prevenir loops para o RP, para FWD porque jão não há loops!

## h)



