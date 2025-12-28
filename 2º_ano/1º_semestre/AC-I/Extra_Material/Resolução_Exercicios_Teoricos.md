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
		_ _ _ _ _          _ _  _ _  _ _    _ _ _ _ _ _ _ _ _ _ _ _ _
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

