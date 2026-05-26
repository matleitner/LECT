# IPv4 network setup 


## Comandos:

```
### Router 1 ###

conf t 
int f0/0 
ip address 192.1.3.1 255.255.255.0
no shut
int f0/1
ip address 200.20.3.1 255.255.255.0
ip ospf 1 area 0
no shut
end 
wr

### Router 2 ### 
conf t 
int f0/0 
ip address 192.2.4.2 255.255.255.0
no shut
int f1/0
ip address 200.20.2.2 255.255.255.0
ip ospf 1 area 0
no shut

end 
wr
### Router 3 ### 

conf t 
int f0/0 
ip address 192.1.3.3 255.255.255.0
no shut
int f0/1
ip address 192.3.5.3 255.255.255.0
no shut
int f1/0
ip address 200.10.1.3 255.255.255.0
ip ospf 1 area 0
no shut
end 
wr
### Router 4 ###

conf t 
int f0/0 
ip address 192.2.4.4 255.255.255.0
no shut
int f0/1
ip address 200.40.0.4 255.255.255.0
no shut
int f1/0
ip address 192.4.5.4 255.255.255.0
no shut
int f1/1 
ip address 200.40.1.4 255.255.255.0
no shut
end 
wr

### Router 5 ###

conf t 
int f0/0 
ip address 200.30.0.5 255.255.255.0
no shut
int f0/1
ip address 192.3.5.5 255.255.255.0
no shut
int f1/0
ip address 192.4.5.5 255.255.255.0
no shut
int f1/1 
end 
wr

### Router 6 ###

conf t 
int f0/0 
ip address 200.20.1.6 255.255.255.0
no shut
ip ospf 1 area 0
int f0/1
ip address 200.20.3.6 255.255.255.0
ip ospf 1 area 0
no shut
int f1/0
ip address 200.20.2.6 255.255.255.0
ip ospf 1 area 0
no shut
int f1/1 
ip address 200.20.0.6 255.255.255.0
no shut
ip ospf 1 area 0
end 
wr

### Router 7 ### 



conf t 
int f0/0 
ip address 192.7.8.7 255.255.255.0
no shut
int f0/1
ip address 200.20.1.7 255.255.255.0
ip ospf 1 area 0
no shut
end 
wr
### Router 8 ###


conf t 
int f0/0 
ip address 192.7.8.8 255.255.255.0
no shut
int f0/1
ip address 200.50.0.8 255.255.255.0
no shut
end 
wr
### Router 9 ### 

conf t 
int f0/0 
ip address 200.10.1.9 255.255.255.0
ip ospf 1 area 0
no shut
int f0/1
ip address 200.10.0.9 255.255.255.0
ip ospf 1 area 0
no shut
end 
wr

#### PC1 ####

ip 200.10.0.100/24 200.10.0.1
save
#### PC2 ####

ip 200.40.0.100/24 200.40.0.4
save
#### PC3 ####

ip 200.40.1.100/24 200.40.1.4
save
#### PC4 ####

ip 200.30.0.100/24 200.30.0.5
save
#### PC5 ####

ip 200.50.0.100/24 200.50.0.8
save
#### PC6 ####

ip 200.20.0.100/24 200.20.0.6
save

```


# 2. BGP: Autonomous System with one Border Router

```
R4 

conf t
router bgp 400
neighbor 192.4.5.5 remote-as 300
network 200.40.0.0
network 200.40.1.0
end
write

R5

conf t
router bgp 300
neighbor 192.4.5.4 remote-as 400
neighbor 192.3.5.3 remote-as 100
network 200.30.0.0
end 
wr



R3 

conf t
router bgp 100
neighbor 192.3.5.5 remote-as 300
redistribute ospf 1 
end 
wr


```


### e.

OPEN 

KEEPALIVE 
BGP UPDATE

### i.

```
conf t
router ospf 1
default-information originate always
end
write

```

### j.

Isto junta, o BGP agrega os ips todos do AS e envia num só, em vez de 2 redes distintas, junta numa só, isto pode não ser assim tão vantajoso....

```
conf t
router bgp 100
aggregate-address 200.10.0.0 255.255.254.0 summary-only
end
wr
```


No R5 `B     200.10.0.0/23 [20/0] via 192.4.5.5, 00:00:13
`, R3 anuncia ao AS 300 como tendo uma so rede.

# 3. BGP: Autonomous Systems with multiple Border Routers

```
Parte 1

R1

configure terminal
interface f0/0
no shutdown
ip address 192.1.3.1 255.255.255.0
interface f0/1
no shutdown
ip address 200.20.3.1 255.255.255.0
end
write

R2

configure terminal
interface f0/0
no shutdown
ip address 192.2.4.2 255.255.255.0
interface f1/0
no shutdown
ip address 200.20.2.2 255.255.255.0
end
write

R3

configure terminal
interface f0/0
no shutdown
ip address 192.1.3.3 255.255.255.0
interface f0/1
no shutdown
ip address 192.3.5.3 255.255.255.0
interface f1/0
no shutdown
ip address 200.10.1.3 255.255.255.0
end
write

R4

configure terminal
interface f0/0
no shutdown
ip address 192.2.4.4 255.255.255.0
interface f0/1
no shutdown
ip address 200.40.0.4 255.255.255.0
interface f1/0
no shutdown
ip address 192.4.5.4 255.255.255.0
interface f1/1
no shutdown
ip address 200.40.1.4 255.255.255.0
end
write

R5

configure terminal
interface f0/0
no shutdown
ip address 200.30.0.5 255.255.255.0
interface f0/1
no shutdown
ip address 192.3.5.5 255.255.255.0
interface f1/0
no shutdown
ip address 192.4.5.5 255.255.255.0
end
write

R6

configure terminal
interface f0/0
no shutdown
ip address 200.20.1.6 255.255.255.0
interface f0/1
no shutdown
ip address 200.20.3.6 255.255.255.0
interface f1/0
no shutdown
ip address 200.20.2.6 255.255.255.0
interface f1/1
no shutdown
ip address 200.20.0.6 255.255.255.0
end
write

R7

configure terminal
interface f0/0
no shutdown
ip address 192.7.8.7 255.255.255.0
interface f0/1
no shutdown
ip address 200.20.1.7 255.255.255.0
end
write

R8

configure terminal
interface f0/0
no shutdown
ip address 192.7.8.8 255.255.255.0
interface f0/1
no shutdown
ip address 200.50.0.8 255.255.255.0
end
write

R9

configure terminal
interface f0/0
no shutdown
ip address 200.10.1.9 255.255.255.0
interface f0/1
no shutdown
ip address 200.10.0.9 255.255.255.0
end
write

OSPF

R9

configure terminal
interface f0/0
ip ospf 1 area 0
interface f0/1
ip ospf 1 area 0
end
write

R3

configure terminal
interface f1/0
ip ospf 1 area 0
end
write

R1

configure terminal
interface f0/1
ip ospf 1 area 0
end
write

R2

configure terminal
interface f1/0
ip ospf 1 area 0
end
write

R7

configure terminal
interface f0/1
ip ospf 1 area 0
end
write

R6

configure terminal
interface f0/1
ip ospf 1 area 0
interface f1/0
ip ospf 1 area 0
interface f0/0
ip ospf 1 area 0
interface f1/1
ip ospf 1 area 0
end
write

----------------------------------------
Parte 2

BGP

R5

configure terminal
router bgp 300
neighbor 192.4.5.4 remote-as 400
network 200.30.0.0
end
write

R4

configure terminal
router bgp 400
neighbor 192.4.5.5 remote-as 300
network 200.40.0.0
network 200.40.1.0
end
write

R5

configure terminal
router bgp 300
neighbor 192.4.5.4 remote-as 400
neighbor 192.3.5.3 remote-as 100
network 200.30.0.0
end
write

R3

configure terminal
router bgp 100
neighbor 192.3.5.5 remote-as 300
redistribute ospf 1
end
write

2i) 

R3

configure terminal
router ospf 1
default-information originate always
end
write

2k)

R3

configure terminal
router bgp 100
aggregate-address 200.10.0.0 255.255.254.0 summary-only
end
write

R4

configure terminal
router bgp 400
aggregate-address 200.40.0.0 255.255.254.0 summary-only
end
write

--------------------------------------

Parte 3

3a)

R3

configure terminal
router bgp 100
neighbor 192.1.3.1 remote-as 200
end
write

R1

configure terminal
router bgp 200
neighbor 192.1.3.3 remote-as 100
redistribute ospf 1
end
write

3d)

R4

configure terminal
router bgp 400
neighbor 192.2.4.2 remote-as 200
end
write

R2

configure terminal
router bgp 200
neighbor 192.2.4.4 remote-as 400
redistribute ospf 1
end
write

3g)

R1

configure terminal
router bgp 200
neighbor 200.20.2.2 remote-as 200
end
write

R2

configure terminal
router bgp 200
neighbor 200.20.3.1 remote-as 200
end
write

3j)

R1

configure terminal
router bgp 200
neighbor 200.20.2.2 next-hop-self
end
write

R2

configure terminal
router bgp 200
neighbor 200.20.3.1 next-hop-self
end
write

3o)

R1

configure terminal
interface tunnel 0
tunnel source 200.20.3.1
tunnel destination 200.20.2.2
ip address 192.1.2.1 255.255.255.0
end
write

R2

configure terminal
interface tunnel 0
tunnel source 200.20.2.2
tunnel destination 200.20.3.1
ip address 192.1.2.2 255.255.255.0
end
write

R1

configure terminal
router bgp 200
no neighbor 200.20.2.2
neighbor 192.1.2.2 remote-as 200
neighbor 192.1.2.2 next-hop-self
end
write

R2

configure terminal
router bgp 200
no neighbor 200.20.3.1
neighbor 192.1.2.1 remote-as 200
neighbor 192.1.2.1 next-hop-self
end
write

3r)

R1

configure terminal
router ospf 1
default-information originate always metric 1
end
write

R2

configure terminal
router ospf 1
default-information originate always metric 2
end
write

3t)

R1

configure terminal
router bgp 200
bgp default local-preference 150
end
write
clear ip bgp *

3v)

R1

configure terminal
ip as-path access-list 1 permit ^$
router bgp 200
neighbor 192.1.3.3 filter-list 1 out
end
write

R2

configure terminal
ip as-path access-list 1 permit ^$
router bgp 200
neighbor 192.2.4.4 filter-list 1 out
end
write

No final:

R1

configure terminal
router bgp 200
no neighbor 192.1.3.3 filter-list 1 out
end
write

R2

configure terminal
router bgp 200
no neighbor 192.2.4.4 filter-list 1 out
end
write
--------------------------------------

Parte 4

R7

configure terminal
router bgp 200
neighbor 192.7.8.8 remote-as 65000
neighbor 192.1.7.1 remote-as 200
neighbor 192.2.7.2 remote-as 200
redistribute ospf 1
end
write

R8

configure terminal
router bgp 65000
neighbor 192.7.8.7 remote-as 200
network 200.50.0.0
end
write

R1

configure terminal
router bgp 200
neighbor 192.1.7.7 remote-as 200
neighbor 192.1.7.7 next-hop-self
end
write

R2

configure terminal
router bgp 200
neighbor 192.2.7.7 remote-as 200
neighbor 192.2.7.7 next-hop-self
end
write

R1

configure terminal
int tunnel 1
tunnel source 200.20.3.1
tunnel destination 200.20.1.7
ip address 192.1.7.1 255.255.255.0
end
write

R7

configure terminal
int tunnel 1
tunnel source 200.20.1.7
tunnel destination 200.20.3.1
ip address 192.1.7.7 255.255.255.0
end
write

R2

configure terminal
int tunnel 2
tunnel source 200.20.2.2
tunnel destination 200.20.1.7
ip address 192.2.7.2 255.255.255.0
end
write

R7

configure terminal
int tunnel 2
tunnel source 200.20.1.7
tunnel destination 200.20.2.2
ip address 192.2.7.7 255.255.255.0
end
write
```



