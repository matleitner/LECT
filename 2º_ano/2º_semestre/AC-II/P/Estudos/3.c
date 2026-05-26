#include <detpic32.h>
#define VECTOR_UART2 32
volatile int counter = 15;
void cfgUART2(){
	int baudrate = 9600;
	int value = ((PBCLK + 8 * baudrate) / (16 * baudrate)) -1;

	U2BRG = value; 
	
	U2MODEbits.BRGH = 0;
	
	U2MODEbits.STSEL = 1;
	U2MODEbits.PDSEL = 2;
	U2STAbits.UTXEN = 1;
	U2STAbits.URXEN = 1;
	
	U2MODEbits.ON = 1;


	U2STAbits.URXISEL = 0; // Use  
	
	IPC8bits.U2IP = 2;
	IFS1bits.U2RXIF = 0;
	IEC1bits.U2RXIE = 1;	
	IEC1bits.U2TXIE = 0;
}




void putc(char byte){
	while(U2STAbits.UTXBF == 1);
	U2TXREG = byte;
}


void putStr(char* string){
	while(*string != '\0'){
		putc(*string);
		string++;
	}
}

void taskU(){
	counter = (counter + 1) % 16;
	LATE = (LATE & 0xffe1) | (counter<<1);
}

void taskR(){

	counter = 0;
	putStr("RESET\r\n");
	LATE = (LATE & 0xffe1) | (counter<<1);

}

void _int_(VECTOR_UART2) isr_U2(void){

	if(IFS1bits.U2RXIF == 1){
		if(U2STAbits.OERR == 1)
    		U2STAbits.OERR = 0;
		char input = U2RXREG;	
		if(input == 'U'){
			taskU();

		} else if(input == 'R'){
			
			taskR();

		}

		
		IFS1bits.U2RXIF = 0;
	}
}


int main(void){
	TRISE = TRISE & 0xFFe1;
	cfgUART2();
	LATE = LATE & 0xFF01;
	EnableInterrupts();


	while(1){

		
		IdleMode();



	}



	

	

	return 0;
}
