# Resolução de exercicios do guião 2

# 1. 


## a) 

## b) 
---
- YES
- Arp request ARP reply, ICMP request/reply
- Arp request

---


- OK
- ARP Request Reply , ICMP Request e reply
- ARP  Request Reply, ICMP request e reply

---

- No
- Arp request
- ARP Request

---

- No
- ARP request para descobrir o MAC do DGW
- ARP request para descobrir o MAC do DGW
 
---
- Ok
- ARP req reply, ICMP request reply
- ARP request
 
 
---
 
- No
- ARP request
- ARP request

# 2. 

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

|----|-----|----|------|---------|------------| 

|PC1   | 192.20.1.1  | YES  | ICMP  ARP requests VLAN10 replies VLAN20 | ARP request    |    

|PC1   | 192.20.1.2  | YES  | TUDO  | IGUAL    | 

|PC1   | 192.30.1.1  |  YES  |  ↑   |  ==  |  

|PC1   | 192.40.1.1  | YES   |  ↑==    | ↑==   |     

|PC1   | 192.1.1.2   | YES   |  ↑   |  ↑  |     

|PC7   | 192.10.1.3  | YES   |  TUDO   | ARP/ICMP Request e Reply|    

|PC7   | 192.1.1.3   |  YES  |  TUDO   | ↑==  |






