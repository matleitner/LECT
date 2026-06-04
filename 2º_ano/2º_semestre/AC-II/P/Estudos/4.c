#include <detpic32.h>

void cfgUART2(){
	// 9600,O,8,2
	int baudrate = 9600;
	U2MODEbits.BRGH = 0;
	U2BRG = (PBCLK + 8 * baudrate)/(16 * baudrate);

	U2MODEbits.STSEL = 1;
	U2MODEbits.PDSEL = 2;
	
	U2STAbits.UTXEN = 1;
	U2STAbits.URXEN = 1;
	
	IEC1bits.U2TXIE = 0;
	IEC1bits.U2RXIE = 1;

	IFS1bits.U2RXIF = 0;
	IPC8bits.U2IP = 2;
	U2STAbits.URXISEL = 0;
	U2MODEbits.ON = 1;



}
void putc(char c){

	while(U2STAbits.UTXBF == 1);
	U2TXREG = c;

}

void putSTR(char* str){
	while(*str != '\0'){

		putc(*str);
		str++;
	}

}
volatile char lastChar = '0';
void _int_(32) isr_UART2(void){
	
	if(IFS1bits.U2RXIF == 1){

		if(U2STAbits.OERR == 1) U2STAbits.OERR = 0;
		char input = U2RXREG;
		
		if(input == 'D'){
			putSTR("\nDSD=");
			int number = PORTB & 0xF;
			
			putc(number/10 + '0');
			putc(number%10 + '0');
			putc('\n');
		}
		if(input != lastChar){
			LATEbits.LATE7 = !LATEbits.LATE7;
		}
		lastChar = input;
		putc(input);

		IFS1bits.U2RXIF = 0;




	}

	
	

}

int main(void){

	cfgUART2();
	TRISEbits.TRISE7 = 0;
	TRISB = (TRISB | 0x000F);
	EnableInterrupts();

	while(1){
		IdleMode();
	}





	return 0;
}
