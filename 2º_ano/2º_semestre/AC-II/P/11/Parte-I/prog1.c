#include <detpic32.h>
#define VECTOR_UART2 32
char* string = "AC2-Guiao 11";

void putc(char byte){
	while(U2STAbits.UTXBF == 1);
	U2TXREG = byte;
}

void _int_(VECTOR_UART2) isr_uart2(void){
	if(IFS1bits.U2RXIF == 1){
		char inputCHAR = U2RXREG;
		if(inputCHAR == '?'){
			char* a = string;
			while(*a != '\0'){
				putc(*a++);
			}
			putc('\n');
		
		}
		else if(inputCHAR == 'T'){
			LATCbits.LATC14 = 1;		
		}
		else if(inputCHAR == 't'){
			LATCbits.LATC14 = 0;
		}	
	}


	IFS1bits.U2RXIF = 0; 
}

int main(void){
	TRISCbits.TRISC14 = 0;
	
	// Configure UART2: 115200, N, 8, 1
	int baudrate = 115200;
	U2BRG = (PBCLK + 8 * baudrate) / (16 * (baudrate)) -1;
	U2MODEbits.BRGH = 0; // 0 para o fator de divisão ser 16, se o FD for 4 o bit tem que ser 0; 
	U2MODEbits.PDSEL = 0;	// 0 : No parity bit, 8 bits size 
	U2MODEbits.STSEL = 0;	// 0 : 1 stop bit
	
	U2STAbits.UTXEN = 1;
	U2STAbits.URXEN = 1;

	
	U2MODEbits.ON = 1;
	

	// Configure UART2 interrupts, with RX interrupts enabled
	// and TX interrupts disabled:
	// enable U2RXIE, disable U2TXIE (register IEC1)
	IEC1bits.U2RXIE = 1;
	IEC1bits.U2TXIE = 0;

	// set UART2 priority level (register IPC8)
	IPC8bits.U2IP = 2; 
	// clear Interrupt Flag bit U2RXIF (register IFS1)
	IFS1bits.U2RXIF = 0;
	// define RX interrupt mode (URXISEL bits)
	U2STAbits.URXISEL = 0;
	// Enable global Interrupts
	EnableInterrupts();

	while(1)
	{
		IdleMode();
	}
	
	return 0;
}
