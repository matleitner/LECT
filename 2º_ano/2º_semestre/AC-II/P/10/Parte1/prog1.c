#include <detpic32.h>


// 1. 
// 
// Baud_real = 104166;
// Erro = (104166 - 115200 ) / 115200 * 100 =  −9.58 % 

int main(void){
	// Configuração do UART
	int baudrate = 115200;

	// Configurar o gerador de baudrate	
	U2BRG = (PBCLK + 8 * baudrate) / (16 * (baudrate)) -1;
	U2MODEbits.BRGH = 0; // 0 para o fator de divisão ser 16, se o FD for 4 o bit tem que ser 0;
	
	// 2- Configurar parâmetros da trama: dimensão da palavra e tipo de paridade
	U2MODEbits.PDSEL = 0;	// 8 bits sem paridade
	U2MODEbits.STSEL = 0;	// 1 bit de stop
		
	// 3- Ativar os módulos de transmissão e receção 
	U2STAbits.UTXEN = 1; 	// Módulo transmissão 
	U2STAbits.URXEN = 1;	// Módulo receção

	// 4- Ativar a UART
	
	U2MODEbits.ON = 1;
}
