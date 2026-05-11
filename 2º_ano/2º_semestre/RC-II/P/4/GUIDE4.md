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



