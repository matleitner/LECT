#include <detpic32.h>
#include <string.h>

#define VECTOR_UART2 32
#define MAXSIZESTRING 100
typedef struct { 
	char mem[MAXSIZESTRING];
	int nchar;
	int posrd;
} t_buf;

volatile t_buf txbuf;


void putstrInt(char *s){
	while(txbuf.nchar > 0); 
	
	while(*s != '\0' && txbuf.nchar < MAXSIZESTRING){
		txbuf.mem[txbuf.posrd++] = *(s);
		txbuf.nchar++;
		s++;
	}

	txbuf.posrd = 0;
	
	IEC1bits.U2RXIE = 0;
	IEC1bits.U2TXIE = 1;
}


void _int_(VECTOR_UART2) isr_uart2(void){

	if(IFS1bits.U2TXIF == 1){
		
		if(txbuf.nchar > 0) { 
			U2TXREG = txbuf.mem[txbuf.posrd];
			txbuf.posrd++;
			txbuf.nchar--;
		} else {
			// Disable UART2 Tx interrupts
			IEC1bits.U2TXIE = 0;
		}
		IFS1bits.U2TXIF	= 0;
	}

}


int main(void) {
	// Configure UART2: 115200, N, 8, 1
	int baudrate = 115200;

	U2BRG = (PBCLK + 8 * baudrate) /(16 * baudrate) - 1;
	U2MODEbits.BRGH = 0;
	U2MODEbits.PDSEL = 0;
	U2MODEbits.STSEL = 0;
	
	U2STAbits.UTXEN = 1;
	U2STAbits.URXEN = 1;
	U2MODEbits.ON = 1;

	// Configure UART2 interrupts, with RX and TX interrupts DISABLED
	// disable U2RXIE, disable U2TXIE (register IEC1)
	IEC1bits.U2RXIE = 0;
	IEC1bits.U2TXIE = 0;
	
	// set UART2 priority level (register IPC8)
	IPC8bits.U2IP = 2;
	// define TX interrupt mode (UTXISEL bits)
	U2STAbits.UTXISEL = 0;
	// Enable global Interrupts
	EnableInterrupts();
	// Initialize buffer variable "nchar" with 0
	txbuf.nchar = 0;
	
	while(1)
	{
		putstrInt("Test string which can be as long as you like, up to a maximum of 100 characters\n");
		resetCoreTimer();
		while(readCoreTimer() < 2000000);

	}
	return 0;
	
}
