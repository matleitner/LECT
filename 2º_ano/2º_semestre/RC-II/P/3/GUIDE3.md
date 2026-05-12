# IPv4 network setup


```
R1

conf t 
int f0/0
no shutdown
ip ospf 1 area 0
ip address 192.168.1.1 255.255.255.0

int f0/1
no shutdown
ip ospf 1 area 0
ip address 192.1.4.1 255.255.255.0


int f1/0
no shutdown
ip ospf 1 area 0
ip address 192.1.5.1 255.255.255.0

interface loopback 0
ip address 200.1.1.1 255.255.255.255
no shutdown
ip ospf 1 area 0

end
wr

R2


conf t 
int f0/0
no shut
ip address 192.168.2.2 255.255.255.0
ip ospf 1 area 0

int f0/1
no shut
ip ospf 1 area 0
ip address 192.2.3.2 255.255.255.0


int f1/0
no shut
ip ospf 1 area 0
ip address 192.2.4.2 255.255.255.0
 

int loopback 0
ip address 200.2.2.2 255.255.255.255
no shut
ip ospf 1 area 0
end
wr

R3


conf t 
int f0/0
no shut
ip ospf 1 area 0
ip address 192.168.3.3 255.255.255.0

int f0/1
no shut
ip ospf 1 area 0
ip address 192.2.3.3 255.255.255.0


int f1/0
no shut
ip address 192.3.5.3 255.255.255.0
ip ospf 1 area 0

int loopback 0
ip address 200.3.3.3 255.255.255.255
no shut
ip ospf 1 area 0
end
wr


R4

conf t 
int f0/0
ip ospf 1 area 0
ip address 192.1.4.4 255.255.255.0
no shut

int f0/1
no shut
ip ospf 1 area 0
ip address 192.1.5.4 255.255.255.0


int f1/0
no shut
ip ospf 1 area 0
ip address 192.2.4.4 255.255.255.0

end
wr

R5


conf t 
int f0/0
no shut
ip ospf 1 area 0
ip address 192.1.5.5 255.255.255.0

int f0/1
no shut
ip ospf 1 area 0
ip address 192.4.5.5 255.255.255.0


int f1/0
no shut
ip ospf 1 area 0
ip address 192.3.5.5 255.255.255.0

end
wr


PC1

ip 192.168.1.100/24 192.168.1.1
save


PC2

ip 192.168.2.100 192.168.2.2
save

PC3

ip 192.168.3.100 192.168.3.3
save

```
# 2. IP Tunnelling 



```

R1 

conf t
interface tunnel 0
tunnel source 192.1.4.1
tunnel destination 192.2.4.2
tunnel mode ipip
ip address 192.1.2.1 255.255.255.0
end 
wr

R2 

conf t
interface tunnel 0
tunnel source 192.2.4.2
tunnel destination 192.1.4.1
tunnel mode ipip
ip address 192.1.2.2 255.255.255.0
end 
wr

```

### a)

Foram adicionadas estas entradas na routing table do R1:

192.1.2.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.1.2.0/24 is directly connected, Tunnel0

L        192.1.2.1/32 is directly connected, Tunnel0


E do R2:

192.1.2.0/24 is variably subnetted, 2 subnets, 2 masks

C        192.1.2.0/24 is directly connected, Tunnel0

L        192.1.2.2/32 is directly connected, Tunnel0

### b) 


No ponto 2.b, observam-se pacotes ICMP apenas na rede 192.1.4.0/24 porque o túnel foi configurado com os endereços das interfaces físicas como terminais (endpoints). O funcionamento baseia-se no encapsulamento: o pacote ICMP original (com IPs 192.1.2.x) é colocado dentro de um novo pacote IPv4 cujos endereços de origem e destino são os das interfaces físicas de R1 e R2. Os routers no caminho encaminham o pacote com base apenas no cabeçalho exterior

### c) 

O tunnel foi configurado como ip destino o IP da interface f1/0 do R2 se esta interface estiver desligada, o ping não irá resultar.


### d)



```

R1 

conf t
interface tunnel 0
tunnel source 200.1.1.1
tunnel destination 200.2.2.2
tunnel mode ipip
ip address 192.1.2.1 255.255.255.0
end 
wr

R2 

conf t
interface tunnel 0
tunnel source 200.2.2.2
tunnel destination 200.1.1.1
tunnel mode ipip
ip address 192.1.2.2 255.255.255.0
end 
wr

```

Ao usar as Loopbacks como source e destination:  

O túnel torna-se independente da topologia física imediata.  

Desde que exista uma rota na tabela de encaminhamento (via OSPF) para o IP 200.2.2.2, o pacote do túnel será enviado.  

Isto permite redundância: se um link físico falhar, o OSPF recalcula a rota para a Loopback e o túnel continua a funcionar através de outro caminho físico.


### e)

Irá funcionar o ping porque, não depende de 1 interface. 


### f)

```

R1

conf t
ip route 192.168.3.0 255.255.255.0 tunnel 0
end 
write
```
Adiciona uma rota, estática, e por ser através de tunel, aprecece directamente conectado.


### g)


### h)

O ICMP request vai pelo tunnel, porque o path cost é menor por ser estático, o reply é feito pelo trajeto que aprendeu via ospf, porque R3 ainda não foi configurado tunnel nenhum.



# 3. OverLay network

```
R1 

conf t 
interface tunnel 1
tunnel source 200.1.1.1
tunnel destination 200.3.3.3
tunnel mode ipip
ip address 192.1.3.1 255.255.255.0
end 
wr
conf t
ipv6 unicast-routing
interface f0/0


R3

conf t 
interface tunnel 1
tunnel source 200.3.3.3
tunnel destination 200.1.1.1
tunnel mode ipip
ip address 192.1.3.3 255.255.255.0
end 
wr


```
