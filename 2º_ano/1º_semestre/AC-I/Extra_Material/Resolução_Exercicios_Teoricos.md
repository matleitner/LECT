# Perguntas sobre teoria de AC-I 


## 1- Quais são os 3 blocos fundamentais de um sistema computacional?

R:	CPU, Memória, Unidades de I/O

## 2- Quais são os 3 principais blocos funcionais na arquitetura de um CPU?

R: Unidade de Controlo (coordena e controla o funcionamento da CPU), ALU (Arithmetic Logic Unity), 

## 4. Descreva de forma sucinta a função de um compilador.

R: O compilador serve para traduzir linguagens consideradas high-level para assembly language.  

## 5. Descreva de forma sucinta a função de um assembler.

R: Um assembler serve para traduzor codigo em Assembly para bits, (linguagem dos computadores).

## 6. Quantos registos internos de uso geral tem o MIPS?

R: 32.

## 7. No MIPS, qual a dimensão, em bits, que cada um dos registos internos pode armazenar?

R: 32. (4 bytes) 

## 8. Qual a sintaxe, em Assembly do MIPS, de uma instrução aritmética de soma ou subtração?

R: add, sub respetivamente

## 9. O que distingue a instrução srl da instrução sra do MIPS?

R: shift logic right e shift arithmetic right, srl (logic) ele "empurra" todos os bits à direita e acrescenta um 0 ao início, ignorando o sinal do número, sra ele tem em atenção o sinal for exemplo **101**0 srl de 1 bit ficaria 0**101**, sra de 1 bit ficaria **110**1 

## 10. Se $5=0x81354AB3, qual o resultado armazenado no registo destino, expresso em hexadecimal, das

### instruções:
### a. srl $3,$5,1    
1000 0001 0011 0101 0100 1010 1011 0011 ->  0100 0000 1001 1010 1010 0101 0101 1001= 0x409AA559 
### b. sra $4,$5,1
0xC09AA559 


## 11. System calls:

### a. O que é um system call?

R: É a solicitação de um serviço do núcleo do sistema pelo programa que está a ser executado. 

### b. No MIPS, qual o registo usado para identificar o system call a executar?

R: $v0 aka $2

### c. Qual o registo ou registos usados para passar argumentos para os systems calls?

R: $a0, $a1, $a2, $a3  $4 até $7

### d. Qual o registo usado para obter o resultado devolvido por um system call (nos casos em que isso se aplica)?

R: $v0, $2


## 12. Em Arquitetura de Computadores, como definiria o conceito de endereço?

R: Número fixo, único que identifica cada registo de memória. 

## 13. Defina o conceito de espaço de endereçamento de um processador?

R: Gama total de endereços que o CPU consegue referenciar. Exemplo caso do MIPS o espaço de endereçamento é 32 bits, 0x0000 0000 - 0xFFFF FFFF

## 14. Como se organiza internamente um processador? Quais são os blocos fundamentais da secção de dados? Para que serve a unidade de controlo?

R: Processador é organizado em secção de dados ( blocos fundamentais: multiplexers, ALU, Registos internos), Unidade de Controlo serve para coordenar os elementos do datapath, durante a execução de um programa. 
Para a execução de uma instrução o processador faz:
	
**Instruction fetch** (leitura do código maquina da instrução)

**Instruction decode** (descodificação da instrução pela unidade de controlo)

**Operand fetch** (leitura dos operandos)

**Execute** (execução da operação) 

**Store result** (armazenamento do resultado da operação no destino especificado na instrução)

## 15. Qual é o conceito fundamental por detrás do modelo de arquitetura "stored-program"?

R: "stored-program" significa que o programa é guardado na memória, por isso é capaz de executar qualquer instrução suportada.

 
## 16. Como se codifica uma instrução? Que informação fundamental deverá ter o código máquina de uma instrução?
R: A instrução codifica-se sob a forma de um número expresso em binárioA instrução codifica-se sob a forma de um número expresso em binário..
Na codificação da instrução deverá estar presente, qual a operação a executar, qual a localização dos operandos se em registos internos do CPU se na memória externa. Onde colocar os resultados. Qual a próxima instrução a executar.


## 17. Descreva pelas suas próprias palavras o conceito de ISA (Instruction Set Architecture).

R: Conjunto completo de operações que o processador pode realizar e como os programas devem ser escritos para ele. 

## 18. Independentemente do modelo da arquitetura, identifique quantas e quais as classes de instruções que compões o conjunto de instruções executáveis por um processador dessa arquitetura?

R: Processamento, Transferência de informação, Controlo de fluxo de execução. 

## 19. O que carateriza e distingue as arquiteturas do tipo "register-memory" e "load-store"? De que tipo é a arquitetura MIPS?

R: register-memory -> operandos das instruções aritméticas e lógicas residem em registos internos do CPU ou em memória
	 load-store -> ""   "" "" registos internos do CPU de uso geral mas nunca em memória. (MIPS)

## 20. O ciclo de execução de uma instrução é composto por uma sequência ordenada de operações. Quantas e quais são essas operações (passos de execução)?

R: Instruction fethc -> Instruction decode -> Operand fetch -> Execute -> Store result; 

## 21. Como se designa o barramento que permite identificar, na memória, a origem ou o destino da informação transferida?

R: Address bus 

## 22. Qual a finalidade do barramento normalmente designado por Data Bus?

R: transferência de informação exemplo: CPU <-> mem ou CPU <-> input/output

## 23. Os processadores da arquitetura hipotética ZWYZ possuem 4 registos internos e todas as instruções são
## codificadas usando 24 bits. Num dos formatos de codificação existem 5 campos: um OpCode com 5 bits,
## três campos para identificar registos internos em operações aritméticas e lógicas e um campo para
## codificar valores constantes imediatos em complemento para dois. Qual a gama de representação destas
## constantes?
	_ _ _ _ _          _ _  _ _  _ _    _ _ _ _ _ _ _ _ _ 

	_ _ _ _
R:  ^ ^ ^ ^ ^ opcode    rs   rt   rd             [-2¹², 2¹²-1]      
																										
## 24. A arquitetura hipotética ZPTZ tem um barramento de endereços de 32 bits e um barramento de dados de
## 16 bits. Se a memória desta arquitetura for bit_addressable:
 
### a. Qual a dimensão do espaço de endereçamento desta arquitetura? 

R: 2³² bits enderençáveis

### b. Qual a dimensão máxima da memória, expressa em bytes, suportada por esta arquitetura?

R: 2³²/8 = 2²⁹ bytes = 512MB

## 25. Considere agora uma arquitetura em que o respetivo ISA especifica uma organização de memória do tipo
## word-addressable, em que a dimensão da word é 32 bits. Tendo o espaço de endereçamento do
## processador 24 bits, qual a dimensão máxima de memória que este sistema pode acomodar se expresso
## em bytes?

R: 2²⁴ words * 32 bits ou 4 bytes = 2²⁶ bytes  = 64 MB 

## 26. Relativamente à arquitetura MIPS:
### a. Com quantos bits são codificadas as instruções no MIPS?

R: 32 bits

### b. O que diferencia o registo $0 dos restantes registos de uso geral?

R: $0 tem sempre o valor de zero (0x00000000) e apenas pode ser lido. 

### c. Qual o endereço do registo interno do MIPS a que corresponde a designação lógica $ra?

R: registo $31 o último registo. 

## 27. No MIPS, um dos formatos de codificação de instruções é designado por R:
### a. Quais os campos em que se divide este formato de codificação?

R: 6 campos op, rs,rt,rd, shamt, funct


### b. Qual o significado de cada um desses campos?


R: op code (6 bits) rs rt endereço dos registos que contêm 1º e 2º operandos 5 bits cada, rd registo destino onde o resultado vai ser armazenado, shamt sift amount para instruções de deslocamento (5 bits), e funct cpdigo da operação a realizar (6 bits) 

### c. Qual o valor do campo opCode nesse formato?

R: 000000 

### d. O que faz a instrução cujo código máquina é: 0x00000000?

R: op 000 000 é tipo R, rs = $0 , rt = $0, rd = $0, shamt = 0 logo fará 0 bits de possiveis shifts, funct = 0 é um sll $0, $0, 0 

## 28. O símbolo ”>>“ da linguagem C significa deslocamento à direita e é traduzido em assembly por srl ou
## sra (no caso do MIPS). Dê exemplos de casos em linguagem C em que o compilador gera um srl e
## exemplos em que gera um sra.

R: Quando é especificado se o número é signed ou unsigned, por exemplo int x = 2 se eu fizer x  = x >> 1; ele faz sra, se eu especificar que x é unsigned int ele faz srl.

## 29. Qual a instrução nativa do MIPS em que é traduzida a instrução virtual "move $4,$15"?

R: segundo os slides é or $4, $0, $15 , mas na verdade é addu $4, $0, $15.

## 30. Determine o código máquina das seguintes instruções (verifique a tabela na última página):
### a. xor $5,$13,$24  000000 01101 01100 00101 00000 100110  
### b. sub $25,$14,$8  000000 01110 00100 01101 00000 100010
### c. sll $3,$9,7     000000 00000 01001 00011 00111 000000  
### d. sra $18,$9,8    000000 00000 01001 10010 01000 000011


## 31. Traduza para instruções Assembly do MIPS a seguinte expressão aritmética, supondo que x e y são inteiros e residentes em $t2 e $t5, respetivamente (apenas pode usar instruções nativas e não deverá usar a instrução de multiplicação):
## y = -3 * x + 5;
isto é o mesmo que Y = (x - (4 * x)) + 5
```mips
	sll $t5, $t2, 1			# y = 4 * x 
	add $t5, $t2, $t5		# y = x - 4x  = - 3 x		
	addi $t5, $t5, 5		# y = -3x + 5
```
## 32. Traduza para instruções assembly do MIPS o seguinte trecho de código:
### int a, b, c;
### unsigned int x, y, z;
### z = (x >> 2) + y;
### c = (a >> 5) – 2 * b;
### //a:$t0, b:$t1, c:$t2
### //x:$a0, y:$a1, z:$a2

```mips
srl $a2, $a0, 2
add $a2, $a2, $a1 

sra $t2, $t0, 5
sll $t3, $t1, 1
sub $t2, $t2, $t $t3 
```

## 33. Considere que as variáveis g, h, i e j são conhecidas e podem ser representadas por uma variável de 32 bits num programa em C. Qual a correspondência, em linguagem C, às seguintes instruções:
```mips
#a. 
	add h, i, g		# h = i + g 

#b. 
	addi j, j, 1	# j+= 1;
	add h, h, j	#	h += j;
									
```
## 34. Assumindo que g=1, h=2, i=3 e j=4 qual o valor destas variáveis no final das sequências das alíneas da questão anterior?

R: i = 3; g = 1; j = 5; h = 9
 

## 35. Descreva a operação realizada pela instrução assembly "slt" e quais os resultados possíveis?

R: slt compara o Rsrc1 e o Rscr2 e se Rsrc1 for menor que Rsrc2 ele faz set de Rdst a 1, caso constrário seta Rdst a 0

## 36. Qual o valor armazenado no registo $1 na execução da instrução "slt $1, $3, $7", admitindo que:

### a. $3=5 e $7=23 

R: 1

### b. $3=0xFE e $7=0x913D45FC

R: 0 

## 37. Com que registo implícito comparam as instruções "bltz", "blez", "bgtz" e "bgez"?

R: $1 / $at

## 38. Decomponha em instruções nativas do MIPS as seguintes instruções virtuais:
a. blt $15, $3, exit
```mips
	slt $1, $15, $3
	bne $1, $0, exit 

```
b. ble $6,$9,exit
```mips
	slt $1, $6, $9
	beq $1, $0, exit
```
c. bgt $5,0xA3,exit

```mips
	addi $1, $0, 0xA3
	slt $1, $1, $5
	bne $1, $0, exit
```

d. bge $10,0x57,exit
e. blt $19,0x39,exit
f. ble $23,0x16,exit
## 39. Na tradução e C para assembly, quais as principais diferenças entre um ciclo "while(…){…}" e um ciclo "do{…}while(…);" ?

R: while pode não chegar a executar nenhuma vez do while executa sempre pelo menos 1 vez


## 40. Traduza para assembly do MIPS os seguintes trechos de código de linguagem C (admita que a, b e c residem nos registos $4, $7 e $13, respetivamente):
a. if(a > b && b != 0)
		c = b << 2;
	 else
		c = (a & b) ^ (a | b);

b. if(a > 3 || b <= c)
		c = c – (a + b);
	 else
		c = c + (a – 5);
## 41. Como se designa o modo de endereçamento usado pelo MIPS para ter acesso a palavras residentes na memória externa?

R: endereçamento indireto por registo

## 42. Na instrução "lw $3,0x24($5)" qual a função dos registos $3, $5 e da constante 0x24?

R: $3 é para onde vai ser colocado do valor da word lida, 0x24 é o off set, $5 é o registo onde o endereço da memória que se quer ler está, ou seja esta isntrução guarda em $3 o valor lido por $5 + 0x24 

## 43. Qual é o tipo de codificação das instruções de acesso à memória no MIPS? Descreva o seu formato e o significado de cada um dos seus campos?

R: Formato I  op 6 bits rs rt 10 bits  offset 16 bits, rt registo onde será armazenado o valor lido da memoria rs é o registo que tem o endereço para ser lido;

## 44. Qual a diferença entre as instruções "sw" e "sb"?

R: sw escreve na memória 4 bytes (1 word), sb escreve 1 byte 

## 45. O que distingue as instruções "lb" e "lbu"?

R: lb lê o byte em complemento para 2, lbu lê o byte unsigned

## 46. O que acontece quando uma instrução lw/sw tenta aceder a um endereço que não é múltiplo de 4?

R: O MIPS gera uma esceção e acaba o programa

## 47. Traduza para assembly do MIPS os seguintes trechos de código de linguagem C (atribua registos internos para o armazenamento das variáveis i e k ) :
a. int i, k;
	 for(i=5, k=0; i < 20; i++, k+=5);
b. int i=100, k=0;
	 for( ; i >= 0; )
	 {
		i--;
		k -= 2;
	 }
c. unsigned int k=0;
	 for( ; ; )
	 {
		k += 10;
	 }
d. int k=0, i=100;
	 do
		{
			k += 5;
		} while(--i >= 0);

## 48. Sabendo que o OpCode da instrução "lw" é 0x23, determine o código máquina, expresso em hexadecimal, da instrução "lw $3,0x24($5)".

R: 00100011 00101 00011  0000000000100100

## 49. Suponha que o conteúdo da memória externa foi inicializada, a partir do endereço 0x10010000, com os valores 0x01,0x02,0x03,0x04,0x05,0x06,0x07 e assim sucessivamente. Suponha ainda que $3=0x1001 e $5=0x10010000. Qual o valor armazenado no registo destino após a execução da instrução "lw $3,0x24($5)" admitindo uma organização de memória little endian?
						
R: $3 =  0x28272625  <- 0x10010024 

## 50. Considere as mesmas condições da questão anterior. Qual o valor armazenado no registo destino pelas instruções:

a. lbu $3,0xA3($5)
b. lb $4,0xA3($5)

## 51. Quantos bytes são reservados no segmento de dados da memória por cada uma das seguintes diretivas:
### a. L1: .asciiz "Aulas5&6T"    

R:10 bytes 

### b. L2: .byte 5,8,23

R: 3 bytes

### c. L3: .word 5,8,23

R: 12 bytes

### d. L4: .space 5

R: 5 bytes

## 52. Desenhe esquematicamente a memória e preencha-a com o resultado das diretivas anteriores admitindo que são interpretadas sequencialmente pelo Assembler.



## 53. Supondo que "L1:" corresponde ao endereço inicial do segmento de dados, e que esse endereço é 0x10010000, determine os endereços a que correspondem os labels "L2:", "L3:" e "L4:".

L2: 0x1001000A
L3: 0x1001000C
L4: 0x10010018


## 54. Suponha que "b" é um array declarado como "int b[25];":

### a. Como é obtido, em C, o endereço inicial do array, i.e., o endereço a partir do qual está armazenado o seu primeiro elemento?

### b. Supondo uma memória "byte-addressable", como é obtido, em assembly o endereço do elemento "b[6]"?

R: Ao primeiro endereço de b, soma-se 6 * 4 a esse endereço 

## 55. O que é codificado no campo offset do código máquina das instruções "beq/bne" ?

R: O deslocamento que é feito a partir de program counter

## 56. A partir do código máquina de uma instrução "beq/bne", como é formado o endereço-alvo (Branch Target Address)?

R: PC 

## 57. Qual o formato de codificação de cada uma das seguintes instruções: "beq/bne", "j", "jr"?
## 58. A partir do código máquina de uma instrução "j", como se obtém o endereço-alvo (Jump Target Address)?
## 59. Dada a seguinte sequência de declarações:
### int b[25];
### int a;
### int *p = b;
### Identifique qual ou quais das seguintes atribuições permitem aceder ao elemento de índice 5 do array
"b":

|a = b[5];| a = *p + 5;|5 de 26|a = *(p + 5);|a = *(p + 20);|
|--|--|--|--|--|
