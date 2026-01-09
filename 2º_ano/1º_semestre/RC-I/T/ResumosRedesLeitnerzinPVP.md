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
|WAN side addr | LAN side addr|
|---|---|
|||
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

## IPv6

Pode ser formado de forma pseudo aleatória, Através do seu MAC address, ou com prefixos dados pelo router através de mensagens de router advertisment 
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
| Aplicação 1 | Aplicação 2 |
| ----- | ---- | 
|Enviar SYN, SN = x| Receber SYN, Enviar SYN + ACK SN = y AN = x+1 |
|Receber SYN + ACK, Enviar ACK, AN = y+1 | Receber ACK | 

### Resumo 

Estação que quer estabelecer uma ligação, envia SYN e o SN = x, o receptor recebe o SYN e envia com ACK + SYN + o seu SN por exemplo y e AN = x + 1
A estação responde com um ACK e o AN = y + 1
    

## Flow Control 

| Emissor | Receptor |
|----- |----| 
| (Envia 400 bytes) | Enviar W = 2500 |
| DATA 1000 SN = x+1, |ACK, AN = x+1001, W =1500  | 
|DATA 1000 SN = x + 1001,| ACK,AN = x + 2001, W=500; |  
| DATA 500 SN = x + 2001| ACK,AN=x+25001,W=0;|
| | ACK, AN = x +2501, W = 2000 ( Recebe 2000 bytes )|  
| DATA 1000 SN = x + 2501; DATA 500 SN = x + 3501 | ACK, AN = x + 3501, W = 100; ACK, AN = x+ 4001, W = 500 |

### Resumo 

Receptor envia a sua Window W, para o emissor saber quanto é que pode enviar, envia  o seu sequence number SN = x, na tabela é x + 1 mas aqui vou assumir que a sessão está estabelecida por isso (x = o SN inicial já com + 1), por exemplo e o Receptor recebe e envia um ACK, a atualização da janela, e o AN que é x + size data sent neste caso 1000;


- Sequence Number : dados já mandados;
- Acknowledge Number: dados já recebidos;
- O receptor diz quanto consegue receber W (window);
- Sequence Number refere-se ao lado da transmissão, o acknowledge Number e a Window refere-se 


## Para terminar sessão 
| Aplicação 1 | Aplicação 2 | 
|----- |----| 
|Enviar FIN, SN = t| Receber FIN, enviar ACK, AN = t+1|
| Receber ACK | Enviar FIN + ACK, SN = z, AN=t+1| 
| Receber FIN + ACK, Enviar ACK, AN = z + 1 | Receber ACK | 

### Resumo 

Para terminar quem quer terminar envia um FIN e o seu SN por exemplo t, receptor receber FIN e envia ACK AN = t+1 e envia um FIN + ACK com o seu SN por exemplo AN = t + 1, estação recebe FIN + ACK e envia ACK com o AN = z + 1 e recptor recebe e acaba a ligação;  
 

## TCP Round Trip Time and Time out

Como a estação pode saber quanto tempo tem que esperar até desistir de receber um pacote? 

EstimatedRTT = (1-µ) * EstimatedRTT + µ * SampleRTT 

## Caso pacotes sejam perdidos

Por exemplo A quer enviar algo a B, W = 20 pacotes, o tamanho máximo de envio de dados seja 1000, e A **receba 3 acknowledge** develvendo 55000, significa que o B não conseguir receber nada depois do SN de A = 55000, para resolver isso o emissor faz **Fast Retransmit** do pacote SN = 55000, a janela de 20 pacotes **diminui para metade**, caso A não obtivesse nenhuma resposta de ACK de B, iria gerar um **timeout** e A tentaria enviar **1 pacote**.
  
# Aplications 

Elsásticas: usam uma largura de banda que está disponível (por exemplo: trans. ficheiros, e-mail)

Inelásticas: precisam do mínimo de largura de banda (exemplo: chamadas de voz, video)

## Voz

- Inelástica;
- Corre sobre UDP 
- Tolera perdas
- Não tolera delays, variações de delays e pequenas larguras de banda

## Video 
- Inelástica 
- Corre sobre UDP 
- Não tolera perdas
- Pode tolerar delays ou variações de delays se buffering for aplicado 

## Audio gravado 

- Inelástico 
- TCP ou UDP 
- Tolera perdar
- Não tolera delays. delays variation e bandwidth low 



## File Transfer 

- Elastic
- TCP, com garantia de ordem na entrega


# Como conectar Máquinas?
## Sockets e Network Programming 

### Um Socket é identificado por:

- Família: AF_INET (IPv4), AF_INET6 (IPv6)

- Tipos: TCP (SOCK_STREAM), UDP(SOCK_DGRAM) , RAW (SOCK_RAW)

- Endereços: (IP ou path)

- Port: 0 - 65535

**Restrição** 

1 socket por endereço, por porta, por protocolo, por família, por host;

___

Um socket tem que ser associado a um IP/PORT local

Sockets podem ser associados a um endereço específico ou qualquer endereço;
  
... 
___ 


# Aplication Layer 


# TFTP 

## Serviço de transferência de ficheiros com interações cliente/servidor simples;

Este protocolo é implementado sobre o UDP e o porto normalizado do servidor é o **69**. Dado que
o UDP não garante fiabilidade, o TFTP implementa um mecanismo de controlo de fluxos simples
(bem menos complexo que o do TCP) de modo a garantir a integridade da informação transferida
(como veremos ilustrado no próximo slide).
O TFTP baseia-se apenas em 5 tipos de mensagens:

- RRQ: permite o cliente pedir para ler um ficheiro do servidor
- WRQ: permite o cliente pedir para escrever um ficheiro para o servidor
- DATA: permite enviar um conjunto de bytes do ficheiro
- ACK: permite validar a recepção de uma das primitivas anteriores
- ERR: permite sinalizar a impossibilidade de uma das primitivas anteriores

Este serviço envia 1 pacote por vez.  

# FTP 

## Filte Transfer Protocol 

Corre sobre TCP ( é trabalho do TCP retransmitir os pacotes) 

Server Ports: **21** para o controlo da conexão e **20** para cada "data connection"

cliente FTP contacta o servidore na porta 21, (TCP), cliente é autorizado pelo controlo de conexão, depois para a troca de informação de informação o servidor abre outra sessão TCP "data connection" 



# DNS 

## Domain Name System

DNS: basicamente é um mapa entre endereços IPs e nomes;

Funciona em UDP **porta 53**

## Vários servidores DNS 

### Solução iterativa 

Perguntar a cada servidor caso o "default" não consiga "descodificicar

### Solução recurssiva 

Neste modelo, o seu computador (cliente) faz uma única pergunta ao servidor DNS do seu ISP (Provedor). O servidor DNS assume toda a responsabilidade: ele vai atrás de todos os outros servidores até encontrar a resposta final.


# HTTP

## HyperText Transfer Protocol
client: browser que faz o request, recebe e mostra os objetos Web;

servidor: envia objetos em resposta aos requests;

HTTP usa TCP, o cliente inicia uma sessão TCP, cria (uma socket) para o servidor, porta 80 -> servidor aceita -> troca de mensagens HTTP entre o cliente e o servidor -> conexão fechada

## Nonpersistent HTTP 

É enviado um objeto por sessão TCP

## Persistent HTTP

São enviados múltiplos objetos sobre uma conexão TCP entre cliente e servidor 

# Wireless 
 

(Para ethernet) 
# CSMA (Carrier Sense Multiple Access) 


	_ _ _ _ _ _ _ _ _ _ _ _ _ _ 
  PC1         PC2         PC3


Estações transmitem e recebem no mesmo canal;
Podem ocorrer colisões porque as estações estão distantes uma da outra; 


# CSMA / CD (CSMA  com Colision Detection)

	_ _ _ _ _ _ _ _ _ _ _ _ _ _   
  A       B        C        D

A estação **A** detecta o meio livre e inicia a sua transmissão;

A estação **B** pretende transmitir mas não o faz porque detecta o meio  ocupado; a estação **C** inicia a transmissão, **C** deteta a colisão e para de transmitir, **A** detecta a colisão e para de transmitir;

# Wireless Networks 

## Componentes 

- Station (STA)
- Access Point (AP) 
- Basic Service Set (BSS) 
- Extended Service Set (ESS)


## Wired vs. Wireless diferenças


	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
	PC1         PC2         PC3

se PC1 e PC3 envia dados ao mesmo tempo

- Ethernet: o emissor consegue detetar colisões;

- Wireless: radios não conseguem detetar colisões ( half-duplex )


Half-duplex: transmições e receções de informação têm que acontecer alternadamente. Para evitar interferência;


## Wireless MAC


Wired MACs

- Tipíco: CSMA/CD 
- Médio está livre? -> envia 
- "Ouve" para sentir colisões

Wireless? 

O alcance do sinal diminui com o quadrado da distância;
O emissor apenas pode aplicar CS e CD, mas colisões ocorrem no receptor.

## Hidden nodes 
### Hidden terminals

A e C não se ouvem, há colisão em B se A e C enviarem ao mesmo tempo a B, e nem o A nem o C se apercebem que ocorreu colisão;

### Solução

O receptor deteta colisões, o emissor pergunta se o receptor esta a receber tráfego, no caso de não obter resposta ele assume que o canal está ocupado;



# MACA (Multiple Access with Collision Avoidance) 

RTS ( request to send )

CLS ( clear to send )

Os pacotes de (RTS/CTS) contêm:

- Endereço do emissor;
- Endereço do receptor;
- Tamanho do pacote;

É usado em networks com um tráfego ou colisões muito elevados 

### Caso a rede estiver entupida/muitas colisões

Quando ocorre uma colisão, esperam um tempo aleatório antes de tentar de novo, se falhar outra vez, o tempo de espera até voltar a tentar dobra. Há um limite de 16 tentativas até ser descartado 
# Wireless Networks: Como estabelecer uma ligação?


## Joining a BSS 

A estação procura um BSS/AP atrevés de Scanning/Probing

BSS com AP: ambas Autenticação e Associação são necessárias para se conectar a BSS;

## WLAN frames

## 3 tipos de frames 

- controlo: RTS, CTS, ACK;
- management;
- data;

# Scanning 

Para a estação se conectar a BSS ele precisa de entrar em contacto com o AP:

1. Scanning Passivo
2. Scanning Acitvo 


# Scanning Passivo

## Beacon 

## Probe Request/Response 

## Joining BSS with AP: Authentication

## Joining BSS with AP: Association

## Data 


# Segurança em WLANs

## Mecanismos de Autenticação e Autorização 

### Open network


- Network é aberta, IPs são atribuidos por DHCP
- Não é necessário autenticação e o acesso é livre
- É possível ver todo o tráfego na network

### Open network + MAC authentication 
- O controlo do MAC address da estação é adicionado 
- MAC pode ser falsificado 
- Difícil de suportar visitantes
- Impossivel de utilizar em público 

### WEP Protocol 

- A estação precisa de uma "key" password para acessar o AP
- Cabeçalho não é encriptado, todos os detinos e origens estão visiveis
- O controlo de frames não é encriptado
- AP não é autenticado e pode ser falsificado

### WPA and 802.11i (WPA2)

- Login e password - é o user que está autenticado em qualquer lado do mundo
- Não necessita de qualquer password do AP
- Contato para um servidor local e o servidor remoto onde o user pertence
- Encriptado com base no TKIP (Temporal Key Integral Protocol)

A troca de chaves(password) é feita após a troca de Assosiation frames  requests e replys 



# Error detection 

# Código de verifcação de paridade simples 


Junta-se um bit adicional, o bit de paridade, à palavra binária a transmitir 
Bit de paridade escolhido por forma a garantir que a palavra completa tem um número par de 1s (paridade par) ou número ímpar de 1's (paridade ímpar) 

Exemplo (paridade par) 



0 1 0 0 0 0 0 0 1 


1 1 0 0 0 0 0 1 1 



## CRC ( Cyclic-Redundancy Check) 

Mensagem a transmitir: **57268**

Emissor e recetor combinam divisor: 84

No emissor executa-se 57268/84 = 681 + 64/84

O emissor transmite 5726864 
___

A mensagem chega com erros ao recetor: 5754864

Agora 57548 / 84 = 685 + 8/84 

Como resto é diferente de 64 o erro é detetado


(isto em décimal) 


## Em bits

Representa se por Polinómios

- M(x) = x⁴ + x³ + x² + 1 (m = 5); mensagem a enviar 11101 
- G(x) = x³ + 1 (r = 3)
- x^rM(x)= x⁷ + x⁶ + x⁵ + x³;
- R(x) = x² + x;
- T(x) = x^r M(x) + R(x) = x⁷ + x⁶ + x⁵ + x³ + x² + x


Para verificar se uma trama T(x) foi enviada com alguma alteração nos bits, o resto de T(x) + E(x) por G(x) gerador tem que ser 0;


						 
