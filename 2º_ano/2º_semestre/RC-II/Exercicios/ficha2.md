# 1.					


```						
					  VLAN40
					    |
				     ROUTER
VLAN20	\				|
VLAN10  /ROUTER   -  VLAN100 - ROUTERB - VLAN20
						| 
					  routerC
				 		|
					  VLAN30
```


## a) F, a máscara/24 
## b) F, é no CORE1 porque VLAN20 é end-to-end
## c) V,  
## d) F
## e) T
## f) F 
## g) F
## h) F

# 2.


## a) T
## b) T
## c) F
## d) F
## e) T
## f) F  .... mac : 203. ....
## g) T porque o caminho para o Root Bridge é maior se DIST3 passar por CORE2 e depois CORE 1
## h) F
## i) F 
## j) F



Scenario 1: Distributed IP Routing & RIPv2

 a) The interconnection VLAN has the IP address 192.10.10.0/25.

-    False. The routing table of DIST2 clearly shows C 192.10.10.0/24 is directly connected, Vlan100. The subnet mask is /24, not /25.

b) The address 192.20.1.254 is configured in DIST2.

-    False. The scenario states that CORE1 is the default gateway (DG) for end-to-end VLANs (VLANs 10 and 20). Furthermore, DIST2's routing table shows it learns the 192.20.1.0/24 network via RIP (R), meaning the gateway address is not configured locally on DIST2.

c) The address 192.10.10.1 is configured in CORE1.

-    True. DIST2's routing table shows that it reaches the end-to-end VLANs (192.10.1.0/24 and 192.20.1.0/24) via the next hop 192.10.10.1. Since CORE1 is the default gateway for those VLANs, it must hold that 192.10.10.1 IP address on the interconnection VLAN.

d) In a ping from PC1 to the IP address 192.40.1.1, an ICMP Echo Reply packet in VLAN 10 is captured in link CORE1-DIST3.

-    False. PC1 (VLAN 10) sends the packet to its gateway, CORE1. CORE1 routes it to DIST3 (the gateway for VLAN 40) via the interconnection VLAN (VLAN 100). The reply from PC7 will travel back from DIST3 to CORE1 encapsulated in VLAN 100, not VLAN 10.

e) In a ping from PC2 to the IP address 192.10.1.1, there are no ICMP packets captured in link DIST1-CORE3.

-    False. (Note: "CORE3" is likely a typo in the document for "CORE1" ) Assuming it means the DIST1-CORE1 link: PC2 (VLAN 20) and PC1 (VLAN 10) are on different VLANs. PC2 must send the packet to its DG (CORE1). CORE1 then routes it to VLAN 10 and sends it back down to PC1. Therefore, ICMP packets will travel across the DIST1-CORE1 link.

f) In a ping from PC5 to the IP address 192.20.1.3, ARP Request packets are captured in link CORE1-DIST3 in VLAN 20.

-    False. The scenario states trunk links support the minimum required VLANs. Since DIST3 only serves VLAN 40 and uses VLAN 100 for routing, VLAN 20 is pruned from the CORE1-DIST3 link. No VLAN 20 traffic, including ARP requests, will cross it.

g) In a ping from PC5 to the IP address 192.10.10.5, an ICMP Echo Reply packet in VLAN 30 is captured in link CORE1-DIST3.

-    False. 192.10.10.5 is DIST3's interface on the interconnection VLAN (VLAN 100). The reply from DIST3 back to DIST2 (PC5's gateway) will travel over the CORE1-DIST3 link tagged as VLAN 100, not VLAN 30.

h) Link CORE1-DIST1 belongs to the broadcast domain of VLAN 100.

-    False. DIST1 acts strictly as a Layer 2 access switch in this topology and does not participate in the routed interconnection VLAN. Because trunk links only support minimum required VLANs, VLAN 100 is not trunked to DIST1.

# Scenario 2: VRRP & Spanning Tree Protocol (STP)

a) The root bridge has priority 16384.

-    True. The provided STP table for VLAN 10 clearly lists the Root ID Priority as 16384.

b) The port cost of f1/15 of DIST1 is 19.

-    True. Interface f1/15 is a FastEthernet port. The default STP cost for 100 Mbps FastEthernet links is 19, which is also corroborated by the port costs listed in CORE2's STP table.

c) The interface f1/14 of DIST2 is a root interface.

-    False. Based on the STP output, CORE1 is the root bridge (reached via CORE2's f1/3). DIST2 has a direct link to CORE1 via f1/15. The path directly to CORE1 (Cost 19) is better than the path through CORE2 via f1/14 (Cost 19 + 19 = 38). Therefore, DIST2's f1/15 will be its root port, not f1/14.

d) One cannot know the port cost of the interface f1/3 of CORE1.

-    False. Because f1/3 is a standard FastEthernet interface , its default cost is 19.

e) The interface f1/15 of DIST3 is a root interface.

-    True. Similar to DIST2, DIST3 has a direct connection to the root bridge (CORE1) via f1/15. This direct path (Cost 19) makes it the root port compared to the longer path through CORE2.

f) The bridge ID of DIST2 is 32768 c201.196c.0000.

-    False. Looking at CORE2's STP table, interface f1/2 is blocking a BPDU from 32768 c201.196c.0000. Diagrammatically, CORE2's f1/2 connects to DIST3. CORE2's f1/1 (which connects to DIST2) receives a BPDU from c203.32e0.0000. Therefore, DIST2's MAC is c203.32e0.0000, not c201.196c.0000.

g) Changing the port cost of f1/2 of CORE2 to 12 does not change the VLAN 10 spanning tree.

-    True. CORE2's f1/2 connects to DIST3 and is currently in a BLK (blocking) state. Even if you lower CORE2's local port cost to 12, DIST3 still advertises a superior path to the root (Cost 19 directly to CORE1) and has a lower Bridge ID MAC (c201... vs CORE2's c204...). DIST3 will remain the designated port for that segment, and CORE2's f1/2 will remain blocked.

h) In a ping from PC7 to the IP address 192.10.1.1, a ICMP Echo Request in VLAN 10 is captured in link CORE1-CORE2.

-    False. PC7 (VLAN 40) sends traffic to its DG, CORE1. CORE1 routes the packet to VLAN 10 to reach PC1 (192.10.1.1). Because CORE1 is the root bridge for VLAN 10, the link between CORE1 and DIST1 is forwarding. CORE1 will send the packet directly down the CORE1-DIST1 link, bypassing CORE2 entirely.

i) In a ping from PC3 to the IP address 192.30.1.1, a ICMP Echo Request in VLAN 10 is captured in link CORE1-CORE2.

-    True. PC3 (VLAN 10) must send the ping to its DG, which is CORE2. Because of STP for VLAN 10, the direct link from DIST2 to CORE2 (f1/14) is blocked. Therefore, PC3's Layer 2 traffic destined for CORE2's MAC address must travel up to the root bridge (CORE1) via DIST2's f1/15, and then cross the CORE1-CORE2 link to finally reach its gateway.

j) In a ping from PC6 to PC1, the ICMP Echo Requests are sent through the path DIST3 -> CORE2 -> DIST1.
-   False. PC6 and PC1 are both in VLAN 10, so this is pure Layer 2 switching. Because CORE1 is the root bridge, the uplinks from DIST1 and DIST3 to CORE2 are blocked. The active STP path is PC6 -> DIST3 -> CORE1 -> DIST1 -> PC1.
