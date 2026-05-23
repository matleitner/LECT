#include <detpic32.h>

void configUART1(){
	int baudrate = 115200;
	U1BRG = (PBCLK + (8*baudrate))/(16*baudrate) - 1;
	U1MODEbits.BRGH = 0;	// fator divisão 16
	U1MODEbits.PDSEL = 1;	// paridade par
	U1MODEbits.STSEL = 0;
	

	U1STAbits.UTXEN = 1;
	U1MODEbits.ON = 1;
}

void wait(unsigned int ms){
	resetCoreTimer();
	while(readCoreTimer() < ms * (PBCLK / 1000));
}

void putc1(char byte){
	while(U1STAbits.UTXBF == 1);
	U1TXREG = byte;
}

int main(void){
	configUART1();
	
	while(1){
		
	putc1(0x5A);	
	
	wait(10);
	}
	return 0;
}
