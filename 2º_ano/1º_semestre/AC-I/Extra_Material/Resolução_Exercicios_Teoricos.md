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
A instrução codifica-se sob a forma de um número expresso em binárioA instrução codifica-se sob a forma de um número expresso em binário..
Na codificação da instrução deverá estar presente, qual a operação a executar, qual a localização dos operandos se em registos internos do CPU se na memória externa. Onde colocar os resultados. Qual a próxima instrução a executar.
