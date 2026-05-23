#include <detpic32.h>
void putc(char byte){
	while(U2STAbits.UTXBF == 1);
	U2TXREG = byte; 
}


void putstr(char* str){
	while(*str != '\0'){
		putc(*str);
	}

}


void wait(unsigned int ms){
	resetCoreTimer();
	while(readCoreTimer() <  ms * (PBCLK / 1000));
}
char getc(){
	while(U2STAbits.URXDA == 0);
	return U2RXREG;
}
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
	char counter = 0;
	while(1){
		
		
		int i;
		for(i = 3; i>=0; i--){
			if((counter>>i) & 1){
				putc('1');
			}else{
				putc('0');
			}
		
		}
	
		counter = (counter + 1) % 10;
		putc('\n');

		wait(200);
	}

	return 0;
}
