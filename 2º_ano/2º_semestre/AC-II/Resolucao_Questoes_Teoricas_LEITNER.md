# Resolução exercicios teóricos
# INTRODUÇÂO 
---

# 1.

O espaço de endereçamento refere-se à dimensão ou ao conjunto total de endereços que um processador consegue aceder.

# 2.

## a. byte-addressable

Quando dizemos que a organização de memória é byte-addressable, isso significa que a menor unidade de memória que pode ser endereçada individualmente é o byte

## b. bit-addressable

Quando dizemos que a organização de memória é bit-addressable, isso significa que a menor unidade de memória que pode ser endereçada individualmente é o bit

## a. word-addressable

Quando dizemos que a organização de memória é word-addressable, isso significa que a menor unidade de memória que pode ser endereçada individualmente é o word, (4 bytes).

# 4.
## a. Data Bus

Data Bus (Barramento de Dados) Este barramento é o responsável pelo transporte efetivo da informação (instruções e dados) entre diferente blocos do sistema 

## b. Address Bus

Address Bus (Barramento de endereços) Este barramento é o responsável pela identificação e localizar exata dos dados que o CPU pretende aceder.

## c. Control Bus 

Este barramento funciona como coordenador de operações.

# 5. 

Address Bus

# 6.

Control Bus

---
# MICROCONTROLADORES (EMBEDED SYSTEMS)

# 7. 
Um **cross-compiler** é um compilador que corre na plataforma A e que gera o código executável para a plataforma B.

# 8.

**Bootloader** é um programa que reside, de forma permanente, na memória do microcontrolador e que disponibiliza apenas funções básicas de transferência e execução de um programa.

# 9.

## a. 
Os microcontroladores são projetados para realizar tarefas específicas (como controlar um motor) e possuem uma grande variedade de interfaces para interagir com o mundo exterior, sendo ideais para sistemas embebidos e de tempo real.


## b. 
Microcontroladores: frequência baixa
## c.
Vários, (Ex. timmers, ADCs,)
## d. 
baixo

## e. 

pouca energia consumida 
## f.
os microcontroladores são projetados para tarefas específicas e sistemas de tempo real, onde a rapidez de resposta a eventos externos é crítica.


# 10.

Sistema computacional especializado, realiza uma tarefa específica ou o controlo de um determinado dispositivo;


# 11. 

**Arquitetura** de Harvard (evita o hazard estrutural na implementação pipelined que aconteceria com uma única memória), 

**Memória** flash 512 kB + 12 kB Boot flash e 128 kB RAM

---

# MÓDULOS DE I/O

# 12.

## TRIS	
Usada para configuração do porto (entrada ou saida)

## LAT 
Usada para escrever dados num porto de saída

## PORT 
Usada para ler dados de um porto de saída

# 13. 

## a.

Continua a ser possível escrever no registo de saida (LAT). O registo LAT é um componente físico (um conjunto de flip-flops) que armazena o valor de CPU pretende colocar na saída.

## b.

Sim, é perfeitamente possível ler o valor armazenado no registo LAT mesmo quando o porto está configurado como entrada. Como se pode observar no esquema, existe um caminho de leitura interno que liga a saída dos flip-flops do registo LAT de volta ao barramento de dados interno ("Data Line"), permitindo ao CPU verificar o último valor que lá foi escrito.


## c.
O sinal que permite realizar a leitura do valor armazenado no registo LAT é o RD\_LAT

# 14.

## a.

Para obter essa informação, o programa deve realizar uma operação de leitura do registo TRISx correspondente 

## b. 

O sinal de controlo que permite realizar a operação de leitura da configuração do porto (ou seja, a leitura do registo TRIS) é o RD\_TRIS

# 15.

## a. 
saída

## b.
Trata-se de uma escrita de software no registo de saída algo do género LATbits.LATx = 0;

# 16.

## a. 
saída

## b.

O processador está a executar uma instrução de leitura do estado atual do pino (ex: valor = PORTAbits.RA0;). Curiosamente, embora o porto esteja configurado como saída, o hardware permite ler o estado real do pino através do registo PORT para verificar se o nível elétrico corresponde ao esperado.

# 17. ????

# 18. 
Sincronização: Como os sinais provenientes do exterior são assíncronos em relação ao relógio (clock) interno do sistema, estes flip-flops garantem que o valor lido pelo processador está devidamente alinhado com o ciclo de funcionamento do CPU. 

# 19.

##  a

```asm
		.data
		.equ BASE_ADDR_HIGH, 0xBF88
		.equ TRISB, 0x6040
		.equ PORTB, 0x6050
		.equ LATB, 0x6060

		.text
		.globl main
main:	lui 	$t0, BASE_ADDR_HIGH
		lw 		$t1, TRISB($t0)
		ori 	$t1, $t1, 0x00FF
		and 	$t1, $t1, 0x00FF
		sw 		$t1, TRISB($t0)
loop:	lw  	$t2, PORTB($t0)
	    andi	$t2, $t2, 0x00FF 
		li 		$a0, 10
		jal 	delay
		xori 	$t3, $t2, 0x00FF
		andi  	$t3, $t3, 0x00FF
		sll		$t3, $t3, 8
		lw 		$t4, LATB($t0)
		andi 	$t4, $t4, 0x00FF
		or		$t4, $t4, $t3
		sw		$t4, LATB($t0)


		li		$a0, 90
		jal		delay
		j 		loop

		jr 		$ra

delay:
    	mul   $v0, $a0, 20000      
wait:
    	addi  $v0, $v0, -1
    	bne   $v0, $zero, wait
    	jr    $ra
```


# 20.

Modelo de programação do periférico


# 21.

O CPU fica sempre a verificar se o dispositivo está pronto para enviar ou receber dados e depois efetua a transferência **Poling**


# 22. 

Entrada/Saída Programada (Programmed I/O)

# 23. 

O módulo de I/O é a parte do periférico que se liga diretamente aos barramentos do sistema (dados, endereços e controlo), servindo de ponte para o dispositivo físico.

# 24. 

## a.

Na ligação ao barramento de dados devem ser usados portas de tri-state

## b. 

Permitem controlar quando o porto de entrada coloca dados no barramento.

Se dois dispositivos tentassem colocar valores diferentes (um a querer enviar '1' e outro '0') no mesmo fio ao mesmo tempo, ocorreria um curto-circuito, podendo danificar o hardware

---

# Interrupções 

# 25. 

## a.

**Interrupção por Software**: Existe apenas uma entrada de interrupção no CPU e uma única Rotina de Serviço à Interrupção (RSI) para todas as fontes. Quando ocorre uma interrupção, o CPU executa esta RSI genérica, que deve ler o registo de status de cada periférico, um a um, para identificar qual deles gerou o pedido

**Interrupções Vetorizadas** (Identificação por Hardware): A identificação da fonte é realizada automaticamente pelo hardware através de um processo designado por "Interrupt acknowledge cycle". Cada periférico possui um identificador único (vetor), que permite ao CPU saltar diretamente para uma RSI específica para esse dispositivo, eliminando a necessidade de verificar manualmente o estado de todos os periféricos

## b.

pedido - reconhecimento - vetorização - salto para a RSI

## c.

 Quando várias fontes geram interrupções ao mesmo tempo, a ordem pela qual são servidas é determinada pela sua prioridade:

-    Prioridade Fixa: No sistema de múltiplas linhas de hardware, cada linha tem atribuída uma prioridade fixa. O CPU atende sempre em primeiro lugar o pedido proveniente da linha com a prioridade mais elevada.
-    Ordem Física (Daisy Chain): Se os periféricos estiverem organizados numa estrutura em cadeia (daisy chain), a prioridade é definida pela posição física do dispositivo em relação ao CPU. O sinal de reconhecimento percorre a cadeia e é bloqueado pelo primeiro periférico que encontrar com um pedido ativo, sendo este o servido primeiro; assim, os dispositivos mais próximos do CPU têm maior prioridade.
-    Prioridade por Software: No modo de identificação por software, a prioridade é definida pela ordem sequencial com que o programa lê os registos de status dos periféricos dentro da RSI genérica


# 26.

## a Prólogo
É executado logo à entrada da RSI e tem como objetivo salvaguardar o contexto do programa interrompido, transferindo o valor dos registos internos do CPU para a memória (stack) antes que a RSI comece a realizar as suas ações

## b. Epílogo

É executado no final da RSI, após o processamento da interrupção, e serve para repor o contexto original, restaurando os valores dos registos a partir da memória (stack) para o CPU

# 27. 

Overhead, é o custo que o CPU gasta em tarefas que não são a transferência de dados.

# 28.

10 Mhz, taxa de execução 5 MIPS (5 * 10⁶ instr por segundo CPI = 2)

atendimento à interrupção é de 20 ciclos = N\_overhead

a rotina de serviço = 40 instr

logo 40 * 2 = 80 ciclos pelas 40 instruções

10 * 10⁶ / 20 + 80  = 100.000Hz = 100 kHz


# 29. 

F = 40 MHz
CPI = 2.5
f\_intr = 200 kHz
overhead : 75 ciclos 

40 * 10⁶ / x + (75) = 200 000 <=> x = 125 ciclos

2.5 - 1 
125 - y= 125/2.5 = 50


# 30.

100 * 10⁶ / (x/3 + 80) = 500 000 <=> x = 40 instruções

# 31. 

# 32.

# 33. 

## a.

A ordem de colocação dos periféricos na cadeia, relativamente ao CPU, determina a sua prioridade.

## b. 

Interrupt Acknowledge

# 34.

1. Pedido de interrupção ("Ireq"), responde ativando o sinal "Interrupt Acknowledge"

2. O sinal "Inta" percorre a cadeia até ao periférico que gerou a interrupção

3. O periférico que gerou a int coloca o seu identificador (vetor) no barramento de dados e bloqueia a propagação do sinal "Interrupt Acknoledge"

4. O CPU lê o vetor e usa-o como índice na tabela que contém os endereços das RSI ou instruções de salto para as RSI 



# 35. 
Interrupções vetorizadas

# 36.


Caracteriza-se por centralizar a gestão de todos os pedidos numa única estrutura lógica.

O CPU possui apenas uma entrada de interrupção ligada a todos os periféricos através de uma porta lógica OR (ou seja, Ireq=Int1+Int2+…+IntN

--- 

# DMA

# 37. 
Ativa um BusReq para pedir ao CPU permição para controlar os barramentos.
O CPU responde com um BusGrant a permitir. Transfere a informação. DMAC gera uma interrupção no fim da transferência e DMAC desativa o BusReq.

# 38.

Gerar uma interrupção 

# 39.

CPU gera esse sinal para dar permição ao DMA a Bus Master

# 40. 

DMA torna-se o BUS master, Fetch, Liberta os barramento, Espera, Torna se bus master outra vez, Deposit, Liberta, Incrementa source address e dest addressm, incrementa nº bytes/words transferidos, espera, gera interrupção 

# 41. 

# 42. 
**DMA não dedicado para transferir dados precisa de 2 bus cycles**
## a.

1/500*10⁶ * 2 *512 = 2048 ns
## b. 


1/500*10⁶ * 2 *512 * 2 (por que controlador é de 16 bits)  = 4096 ns

# ...

# 44. 

é exatamente igual mas apenas precisa de fazer 1 bus-cycle

# ...

# 47

T = 1/100 * 10⁶= 10 ns

word = 32 bits = 4 Bytes
T\_BC = 2 ciclos relogio = 10 * 2 ns

1. Fetch 2 T\_BC
2. Espera 2 T\_BC
3. Deposit 2 T\_BC
4. Espera 2 T\_BC

8 ciclos relogio 

Taxa = Bytes / Tempo

Taxa = 4 Byt/ 80 *10⁻⁹

Taxa = 50 * 10⁶ Bytes/s


... Lame 

saber que 

Dedicado demora 1 ciclo de barramento 
Não dedicado demora 2 

Modo bloco fetch, deposit 

Modo sycle-stealing, fetch 2 ciclos, espera (1 ciclo), deposit 2 ciclos, espera 1 ciclo 

é 1 ciclo pq diz no enunciado


----

# TIMERS

# 50. 

f\_out = f\_in / (k1 * k2)

# 51.

Duty-cycle é a percetagem a que num ciclo o sinal fica a um.

# 52.

## a. 

20 * 10 ⁶ / 2000 = 10 kHz

# 53.
Garantir um Duty Cycle de 50%


# 54. 

20 * 10 ⁶ /(4 * 2500) = 2000 = 2 kHz
1 / 2kHz = 500 µs

duty cycle:
834 / 2500 = 33,36 %

# 55.

## a.

PBCLK = 50MHz 
f\_out = 85Hz

50 * 10⁶ /(k * 2¹⁶) = 85
k = 50 * 10 ⁶ / 65536 * 85 = 8.9757  = 16

## b.

50 * 10⁶ / (16 * PR2 ) = 85

PR2 + 1  = 50  * 10⁶ / k (85 * 16) => PR2 = 36764


# 57 

## a. 
f_out = 100 Hz 


40 * 10 ⁶/ (k * 2^16)  = 100
k= 8

## b.
 
40 *10 ⁶ / (8 * PR3) = 100
PR3 = 40 * 10 ⁶ /(800) = 50000-1 = 49999

OC5RS / (PR3 +1) = Duty Cycle
0.25 * 50000 = 12500


## c. 

log_2(PR3+1) = 15.6 bits  



# 61 

## a.

1 / 100 000 = 0.00001 s

T_{max} = 2¹⁶ * 0.00001 = 655.36 ms 


---
# Noções Básicas de Barramentos /Descodificação de endereços

# 65.

## a
### i
CS = A15 . A13\ . A11\ 

### ii
¬CS = ¬(A15 . A13\ . A11\ ) = A15\ + A13 + A11



## b

|Combinação (A14 A12 A10)|Endereço Inicial|Endereço Final |Notas|
|---|---|---|---|
0 0 0,0x8000,0x83FF,Gama-Base
0 0 1,0x8400,0x87FF,Réplica 1
0 1 0,0x9000,0x93FF,Réplica 2
0 1 1,0x9400,0x97FF,Réplica 3
1 0 0,0xC000,0xC3FF,Réplica 4
1 0 1,0xC400,0xC7FF,Réplica 5
1 1 0,0xD000,0xD3FF,Réplica 6
1 1 1,0xD400,0xD7FF,Réplica 7


# 66.

## a.

CS\ = A15 + A13\  => CS = A15\ . A13

0 X 1 X A11 .... A0 memoria 


4kB  = 4*1024 = 0xFFF


0 0 10 0x2000 - 0x2FFF

0 0 11 0x3000 - 0x3FFF

0 1 10 0x6000 - 0x6FFF

0 1 11 0x7000 - 0x7FFF

## b.

0x600E

# 67. 

ROM   1111 1000 CS = A15. A14. A13. A12. A11 

verdinho 0001 0000 0000: A15\⋅A14\⋅A13\⋅A12⋅A11\⋅A10\⋅A9\⋅A8\⋅A7\·A6\⋅A5\⋅A4\⋅A3\
laranjinha A15\⋅A14\⋅A13\⋅A12\⋅A11⋅A10\⋅A9\⋅A8\⋅A7\⋅A6\⋅A5\⋅A4\⋅A3\⋅A2\⋅A1\⋅A0\

RAM 0000 0011 F F A15\.A14\.A13\.A12\.A11\.A10\

---

# BARRAMENTOS DE COMUNICAÇÃO EM SÉRIE


# 80.


## a.
Nível da implementação: Menos pinos nos integrados, o que simplifica o design das motherboards e reduz o espaço ocupado. Evita-se também o clock skew (atraso diferencial entre bits paralelos).

## b.
Cablagem de suporte: Requer muito menos condutores (muitas vezes apenas um par diferencial). Isto reduz o peso, o volume e melhora a flexibilidade dos cabos.

## c.
Nível do custo: Menor custo de fabrico de cabos e conectores devido à redução de material condutor e complexidade mecânica.

## d.
Distância de transmissão: Muito superior. Como não sofrem de dessincronização entre linhas paralelas, podem manter a integridade do sinal a distâncias muito maiores.

## e.
Débito de transmissão: Embora pareça contra-intuitivo, os barramentos série modernos (como PCIe ou USB-C) atingem débitos maiores porque conseguem operar a frequências de relógio muito mais elevadas sem interferência eletromagnética (crosstalk) excessiva.

# 81.

## a.
Síncrono: Existe uma base de tempo comum. Topologicamente, isto implica frequentemente a existência de uma linha física de clock dedicada que liga o emissor aos recetores, ou que o clock esteja "embutido" no sinal de dados.

## b.
Assíncrono: Não existe sinal de clock partilhado. A sincronização é feita ao nível do caractere/frame usando bits de Start e Stop. Os relógios locais devem ter a mesma frequência (baud rate), mas não precisam de estar em fase.

# 82.
Linha de Clock Dedicada: Um fio separado transporta o sinal de relógio (ex: I2C, SPI).

Codificação com Clock Embutido: O relógio é extraído das próprias transições do sinal de dados (ex: Manchester, 8b/10b).

# 83.
A Codificação Manchester é um método onde cada bit é representado por uma transição no meio do intervalo de tempo do bit, em vez de um nível de tensão fixo.

    Vantagem: Como há sempre uma transição (0 para 1 ou 1 para 0), o recetor consegue extrair o clock facilmente, mantendo o sincronismo perfeito.


# 84.

Full-Duplex: Comunicação simultânea em ambos os sentidos. Exige normalmente caminhos físicos separados (fios distintos para Tx e Rx).

Half-Duplex: Comunicação em ambos os sentidos, mas um de cada vez. Partilham o mesmo meio físico, exigindo um protocolo de controlo para evitar colisões.

# 85.

## a.
Full-Duplex: SPI (usa linhas MISO e MOSI separadas), UART (com fios TX e RX independentes), RS-232.

## b.

Half-Duplex: I2C (usa apenas uma linha de dados SDA), RS-485 (em configuração de 2 fios), USB (nas versões base).

# 86

Orientada ao Byte (ou Caractere): Os dados são transmitidos em blocos de tamanho fixo (geralmente 8 bits), muitas vezes delimitados por Start/Stop bits. O sistema "pensa" em caracteres.

        Exemplo: UART/RS-232.

    Orientada ao Bit: Os dados são vistos como um fluxo contínuo de bits. Não há necessariamente uma separação rígida por bytes; o protocolo usa sequências especiais de bits (flags) para marcar o início e o fim da mensagem.

        Exemplo: CAN Bus, HDLC, SDLC.

A principal diferença é a eficiência: protocolos orientados ao bit são geralmente mais robustos e eficientes para transmissão de grandes tramas de dados, pois não precisam de bits de controlo para cada pequeno grupo de 8 bits.
