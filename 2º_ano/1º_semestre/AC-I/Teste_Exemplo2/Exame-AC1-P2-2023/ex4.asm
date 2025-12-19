      .data
A:    .double 7.135709    
B:    .asciiz "3BD0F7A2"   
C:    .word   0x8A6, 0x23, 0x16EB, 0x25B8, 0x387A
D:    .space  28       
E:
      .text
      .globl main
main: la     $t0,C
      la     $t1,D
      move   $t2,$t1
      or     $v0,$0,$0
loop: lw     $t3,0($t0)
      srl    $t3,$t3,8
      sw     $t3,4($t1)
      add    $v0,$v0,$t3
      addiu  $t0,$t0,4
      addiu  $t1,$t1,4
      blt    $t0,$t2,loop
endl: sw     $v0,0($t2)
exit: jr     $ra

***Analise o código assembly e responda às questões seguintes. 
***Considere que o segmento de dados do programa começa no endereço 0x10010020
***e que a sua primeira instrução está armazenada no endereço 0x00400034.

#### Resolução:

      .data						# 0x10010020
A:    .double 7.135709    				# 0x10010028
B:    .asciiz "3BD0F7A2" 				# 0x10010028 + 8 + \0 =  0x10010031
C:    .word   0x8A6, 0x23, 0x16EB, 0x25B8, 0x387A	# padding até 0x10010034; 0x10010048
D:    .space  28       					# 0x10010048 + 28 = 0x10010064
E:
      .text
      .globl main
main: 				# int* main() {				
      la     $t0,C		# 	int* pC = C;			0x00400034 (+2 ins (la é virtual))
      la     $t1,D		# 	int* pD = D;			0x0040003C (+2 ins (la é virtual))
      move   $t2,$t1		#	int* origD = D;			0x00400044 (+1 ins (move é virtual, mas é só uma instr.))
      or     $v0,$0,$0		# 	int sum = 0;			0x00400048 (+1 ins)
loop: 				# 	while(pC < origD) {		0x0040004C
      lw     $t3,0($t0)		#		int tmp = (*pC);
      srl    $t3,$t3,8		#		tmp = tmp >> 8;
      sw     $t3,4($t1)		# 		*(pD+1) = tmp;
      add    $v0,$v0,$t3	#		sum += tmp;
      addiu  $t0,$t0,4		#		pC++;
      addiu  $t1,$t1,4		#		pD++;
      blt    $t0,$t2,loop	#	}
endl: 
      sw     $v0,0($t2)		#	origD[0] = sum; (soma dos elems de C>>8);
exit: 
      jr     $ra		# }


Sabendo que a memória está organizada em bytes, o número total de posições de memória ocupado pela diretiva ".word" do trecho de código é:
20

O número total de bytes ocupado pelo segmento de dados do programa (E-A) é:
0x10010064 - 0x10010020 = 0x4 = 16 * 4 + 4 = 68 posições de memória.

O valor do registo $t0 após a execução da primeira instrução do trecho de código é:
0x10010034

O valor do registo $t1 após a execução da segunda instrução do trecho de código é:
0x10010048

O endereço a que corresponde o label "loop" é (tenha em atenção as instruções virtuais do código):
0x0040004C

O número de vezes que o ciclo do programa é executado é:
5

No final da execução do programa o valor do registo $t0, é:
0x10010048

Considerando que o label D referencia um array de inteiros, no final da execução do programa o valor armazenado em D[3] é:
D[3] = C[2] >> 8 = 0x16EB >> 8 = 0x0016

O valor de retorno da função main() é:
(0x8A6, 0x23, 0x16EB, 0x25B8, 0x387A) >> 8 = 0x0008 + 0x0000 + 0x0016+ 0x0025 + 0x0038 =  0x007B

Supondo que se pretendia usar o espaço referenciado pelo label D para um array de "doubles", a dimensão máxima desse array seria:
floor(28 / 8) = 3.