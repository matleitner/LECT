# IP's 

Um endereço IP é representado por 4 números, separados por pontos. Cada número é décimal, e é a representação do seu byte correspondente.  


Ex.:128.10.2.30 


| Class | lowest address| highest address |
| ----- | ------------- | --------------- |
| A     |   1.0.0.0     |  126.0.0.0      |
| D     |   128.0.0.0   |  191.255.0.0    |
| A     |   192.0.0.0   |  223.255.255.0  |
| A     |   224.0.0.0   |  239.255.255.255|
| A     |   240.0.0.0   |  255.255.255.254|

# Máscaras 

A máscara é utilizada para separar a parte de rede da parte de host dos endereços


|    IP    |  10.  | 0.0.1 |
| -------- | ----- | ----- | 
|  Máscara |  255. | 0.0.0 | 
|          |  rede | host  |


# Endereços IP especiais 


| tudo 0's | Este HOST |
| ---  | ---- | 
| tudo 1's | BROADCAST LOCAL |
| ---  | ---- | 
| net | tudo 1's | BROADCAST dirigido para net |
| ---  | ---- | 
| 127 | qualquer ( em geral 1 )  | LOOPBACK |
| ---  | ---- | 
| net | tudo 0's  | esta net |




# Comando ping

O emissor (host ou router) envia uma mensagem do tipo **Echo Request**;

O recetor responde com uma mensagem do tipo **Echo Reply**;

# LANs - Redes de área local

Permitem a comunicação direta entre estações próximas através de ligações partilhadas;




___
# Endereços IEEE

|110111**01** |01110101 |11001111 |01011111 |010000101 |0111101|
|-------------|---------|---------|----------|---------|----|
| 1º oct| 2º oct |3º oct |4º oct |5º oct |6º oct |

- bit G/L (Global/Local) 7o bit do 1º byte 
- bit G/I (Grupo/Individual) 8º bit do 1º byte 

## Tipos de endereços 
- Unicast (G/I = 0) 
- Multcast (G/I = 1) 
- Broadcast (todos os bits a 1)
___

# ARP - Address Resolution Protocol 

Caso um dispositivo tenha um IP datagram, a enviar para outro, esse IP datagram necessita de ser encapsulado numa camada MAC, onde está especificado no cabeçalho o endereço MAC da origem e do destino;

Isto é feito através dos pacotes Request e Reply ARPs.

## ARP Request 

ARP request é um pacote encapsulado na camada MAC. E esse pacote é encapsulado numa Ethernet frame. Nesse frame está o endereço origem e o destion é o MAC broadcast address FF-FF-FF-FF-FF-FF. Ele especifica os endereços MAC e IP origem, mas apenas especifica o IP destino, porque ainda não sabe se o MAC existe;


## ARP Reply

ARP Reply é a resposta caso exista, também encapsulada por Ethernet frame. O endereço  origem é o MAC que recebe o Request, e o destino é para aquele que enviou o Request;
    
  

#  Datagrama IPv4

- **VERSION** 4 bits;
- **Header Length** 4bits tamanho do cabeçalho em blocos de 4 octetos;
- **Service Type** 1 byte;
- **Total Length** 2 bytes;
- **Identification** 2 bytes;
- **Flags** 3 bits;
- **Fragment Offset** 13 bits, posição do fragmento no datagrama original, ( o primeiro fragmento tem o valor 0x00);
- **Time to Live** 1 byte;
- **Protocol** 1 byte;
- **Header CheckSum** 2 bytes;


# Fragmentação e reassemblagem em IP 

Quando um datagrama IP é maior que o MTU (Maxium Transmition Unit), o que envia deve fragmentar em diversos IP datagrams mais pequenos, cujo tamanho não ultrapasse o MTU;
Esta operação pode tanto ser feita pelo host ou qualquer router;

### Exemplo 

Ping de 3100 bytes (MTU 1500 bytes + 14 b cabeçalho Ethernet):

1º fragmento (ID, offset: 0, flags:More):
-	Ethernet: 14 bytes; 
- IP: 20 bytes;
- ICMP: 8 bytes;
- Data: 1472 bytes.
___

2º Fragmento (ID, offset:1480, flags:More):
- Ethernet: 14 bytes;
- IP: 20 bytes;
- Data: 1480(não há cabeçalho ICMP);

___ 

3º Fragmento (ID, offset:2960, flags:No More):
- Ethernet: 14 bytes;
- IP: 20 bytes;
- Data: 148 bytes.


# Switching 

## Tabela de encaminhamento do Switch 
Auto-Aprendizagem:

O switch **aprende** que estações podem ser atingidas por cada uma das suas interfaces;
- quando uma trama é recebida numa interface, o switch regista na tabela de encaminhamento uma entrada com o endereço MAC origam da trama e a enterface de entrada;

por exemplo: ping de A para A'

### switching table:

|MAC addr| interface| TTL|
|---|---| --- |
| A | 1 | 60  |


depois A' responde: 

### switching table:

|MAC addr| interface| TTL|
|---|---| --- |
| A | 1 | 60  |
| A'| 4 | 60  |

# TTL Tempo de vida das entradas das tabelas de encaminhamento

Este valor é "set"ado para eleminar a entrada MAC da tabela caso nenhum frame seja enviado até ao TTL; 

# Routing 

Os routers são elementos da network responsáveis para realizarem forward de cada datagram IP com direção para o host destino;

## IP routing

Para o transmissor descobrir o endereço IP de um recetor que está a 3 routers de distância;

PC1 - R1 - R2 - R3 - PC2 

Contacto de um IP noutra rede:
- ARP na rede para encontrar o endereço físico da default gateway;
- Novo ARP na rede seguinte para encontrar o endereço físico do próximo salto;
- Novo ARP e encontro o endereço e faz o reply;



# ICMP 

- Permite a troca de mensagens de controle e diagnóstico; 
- Os pacotes ICMP são encapsilados nos pacotes IP;
- O campo checksum é determinado com base em toda a mensagem

### cabeçalho MAC  | cabeçalho IP | cabeçalho ICMP 

# ICMP message types

## ICMP Destination Unreachable 

Destino do IP datagram não consegue ser alcançado;

## ICMP Time Exceeded

É enviado pelo router para a origem host por um IP datagram quando é descartado devido ao facto do seu TTL chegar a 0;

## ICMP Redirect 

Quando um router deteta que uma estação está a usar uma rota que não é a melhor envia-lhe uma mensagem ICMP Redirect para que ele mude de rota;

O router inicial, para além do ICMP Redirect, envia também o datagrama original para o destino;

# Subnet 

- Uma subrede é um subconjunto de uma rede de classe A, B ou C
- A utilização de máscaras, permite que uma rede seja dividida em subredes a parte de rede à parte de host do endereço IP 

### Vantagens 

Não faz sentido uma rede precisar de 256 IPs sendo que essa rede necessite de 16, por exemplo;

___

# Virtual LANs

Criar diferentes networks no mesmo switch - usando as portas do switch configurando diferentes VLANs - isso otimiza recursos e limita broadcasts;

As VLANs permitem segmentar a rede de forma lógica (Camada 2 - Link), enquanto antigamente a segmentação era obrigatoriamente física (Camada 3 - Rede). As VLANs transformam uma rede física rígida e limitada em uma estrutura flexível que economiza largura de banda e facilita o gerenciamento organizacional.


___

# Private Addressing 

| PREFIX |
| ------ |
|	172.16/12|
|  10/8  |
|   192.168/16|
| 169.254/16|

Estes endereços podem ser livremente usados em redes privadas;

Pacotes IP com endereços destino a pertencer a estes blocos não é feito o route para a network pública;

Para comunicações com a Internet, os endereços privados têm que ser traduzidos para endereços públicos;

___


# NAT : Network Address Translation 


Traduz endereços privados em públicos, um privado um público;
É útil para servidores que mantenham o mesmo IP público;
 
### Motivação 

Redes locais usam apenas 1 endereço IP

## NAT PAT 

Soluciona o problema de na rede de endereços privados, cada IP privado não precisar de um IP público;
Ou seja PC1 192.168.1.1 o router traduz para 10.0.0.1:21111
      e PC2 192.168.1.2 o router traduz para 10.0.0.1:31111 
Economizando endereços públicos usando apenas um endereço publico por rede privada, indeferente do número de IPs da rede privada. 

# DHCP

## DHCP: Dynamic Host Configuration Protocol 

Permite dinamicamente obter o endereço IP do servidor DHCP quando se conecta à rede;

### Configuração de um servidor DHCP

- Pool de Ips reservados para serem atribuidos;
- Excluir range de IPs
- Endereços reservados
- Lease Time


## Processo de atribuição de IP com DHCP

- host faz broadcast de um "Discover"  
- servidor responde com "Offer" 
- host faz um "request" 
- servidor envia um "ack" 


## Address leasing 

- Renewal Time (50% of Lease Time)

- Rebinding Time (85% of Lease Time)

- Lease Time  

# IPv6

## 16 bytes / 128 bits


| Type | Hexadecimal |
| ---- |  ---------  |
| Global unicast     |  2     | 
| Link-Local | FE80::/10|
| Unique-Local Unicast  | FC00::/8 ou FD00::/8| 
| Multi-Cast | FF00::/16 | 

## IPv6 Interface identifier

### Auto-configures 

MAC addres no 4º byte entre os 4 bits leva FF FE, e o primeiro byte, é 00 se não for único e 02 se for único;



# IPv6 Neighbor Discovery Protocol 

É o protocolo "guarda-chuva" que utiliza mensagens ICMPv6 para gerenciar a interação entre nós no mesmo link. Suas principais funções incluem:

-   Descobrir o endereço da camada de enlace (MAC) de um vizinho.

-   Verificar se um vizinho ainda está alcançável.

-   Detectar endereços IP duplicados (DAD - Duplicate Address Detection).

-   Encontrar roteadores no link.

## IPv6 Neighbor Solicitation

Esta mensagem é o equivalente ao "ARP Request" do IPv4.

-   Função: Um host envia esta mensagem para determinar o endereço MAC de um vizinho ou para verificar se um endereço IP ainda é válido.

-   Exemplo: O PC1 pergunta: "Quem tem o endereço IPv6 2001:db8::1? Por favor, envie-me o seu endereço MAC".
## IPv6 Neighbor Advertisement 

Esta é a resposta à solicitação anterior (equivalente ao "ARP Reply").

-   Função: É enviada em resposta a um Neighbor Solicitation ou de forma espontânea para anunciar uma mudança no endereço MAC.

-   Exemplo: O PC2 responde: "Eu sou o 2001:db8::1 e o meu endereço MAC é 00:AA:BB:CC:DD:EE".

## IPv6 Router Solicitation 

Quando um dispositivo IPv6 entra na rede, ele não quer esperar que um roteador se anuncie; ele toma a iniciativa.

-   Função: O host envia uma mensagem RS para localizar roteadores presentes no link local.

-   Objetivo: Obter informações de configuração de rede (como prefixos de IP) imediatamente para realizar a auto-configuração (SLAAC).


## IPv6 Router Advertisement 

Esta é a mensagem enviada pelos roteadores para informar sua presença e fornecer parâmetros de rede.

-   Função: Pode ser enviada periodicamente pelo roteador ou em resposta direta a um Router Solicitation.

-   Conteúdo: Contém o prefixo da rede (ex: 2001:db8:a::/64), o tempo de vida da rota e se o host deve usar DHCPv6 ou se auto-configurar.

. . .
___ 


# Camada Transporte serviços e protocolos

| Decimal | Palavra-Chave | Protocolo | Descrição |
| ------- | ------------- | --------- | --------- | 
|  20  | FTP-Data | TCP | File Transfer Protocol (dados)|
| 21 | FTP-CONTROL | TCP | File Transfer Protocol (controlo)| 
| 23 | TELNET | TCP | Terminal Connection | 
| 25 | SMTP | TCP | Simple Mail Transport Protocol | 
| 67,68 | BOOTP | UDP | Bootstrap Protocol |
| 53 | DNS | UDP/TCP | Domain Name System | 
| 69 | TFTP | UDP | Trivial File Transfer Protocol | 
| 80 | HTTP | TCP | Hypertext Transfer Protocol | 

# UDP (User Datagram Protocol)

É um serviço que transporta dados sem interrupções;

# TCP (Transmission Control Protocol) 
 
- point-to-point
- flowed controled

## Estrutura do segmento TCP

### RST, SYN, FIN connection setup

## Para estabelecer uma sessão TCP

|Enviar SYN, SN = x| Receber SYN, Enviar SYN + ACK SN = y AN = x+1 |
| ----- | ---- | 
|Receber SYN + ACK, Enviar ACK, AN = y+1 | Receber ACK | 

## Para terminar sessão 
| Aplicação 1 | Aplicação 2 | 
|----- |----| 
|Enviar FIN, SN = t| Receber FIN, enviar ACK, AN = t+1|
| Receber ACK | Enviar FIN + ACK, SN = z, AN=t+1| 
| Receber FIN + ACK, Enviar ACK, AN = z + 1 | Receber ACK | 

 
## Flow Control 

| Emissor | Receptor |
|----- |----| 
|  | Enviar W = 2500 |
|DATA 1000 SN = x+1, DATA 1000 SN = x + 1001,  DATA 500 SN = x + 2001| ACK, AN = x+1001, W = 1500;ACK,AN = x + 2001, W=500; ACK,AN=x+25001,W=0;|
| Receber ACK | Enviar FIN + ACK, SN = z, AN=t+1|  
| Receber FIN + ACK, Enviar ACK, AN = z + 1 | Receber ACK |



