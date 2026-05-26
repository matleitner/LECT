#include <detpic32.h>
volatile int atual = 0;
volatile int inicio = 0;
volatile char buffer[16];
#define VECTOR_U2 32
void cfgUART2(){
	int baudrate = 57600;
	U2BRG = (PBCLK + 8 * baudrate)/(16 * baudrate) - 1;
	U2MODEbits.BRGH = 0;

	U2MODEbits.PDSEL = 1;
	U2MODEbits.STSEL = 0;
	U2STAbits.UTXEN = 1;
	U2STAbits.URXEN = 1;

	U2MODEbits.ON	= 1;

}

void putc(char byte){

	while(U2STAbits.UTXBF == 1);
	U2TXREG = byte;

}

void putstring(char* string){
	while(*string != '\0'){
		putc(*string);
		string++;
	}
}
char getc(){
	while(U2STAbits.URXDA == 0);
	return U2RXREG;
} 

void addPonteiroAtual(){
	if(atual >= 16) inicio = atual%16;
	atual = (atual + 1);

}
void _int_(VECTOR_U2) isr_U2(void){

	char c = getc();
	if(c == 'D'){
		char* str = buffer;
		int i;
		for(i = inicio; i<(inicio+16); i++){
			int index = i%16;	
			char hex = buffer[index] & 0xF;
			printInt(index, 10 | 2<<16);
			putc(':');
			putc(' ');
			putc(hex < 10 ? hex + '0' : hex - 10 + 'A');
			putc(',');
		
		}

		putc('\n');

		while(*str !='\0') {
			*str = '\0';
			str++;
		}
		atual = 0;
		inicio = 0;
		
	}


	IFS1bits.U2RXIF = 0;




}
void cfgUARTint(){
	IEC1bits.U2RXIE = 1;
	IEC1bits.U2TXIE = 0;
	IPC8bits.U2IP   = 2;

	IFS1bits.U2RXIF = 0;
	U2STAbits.URXISEL = 0;
	
}

int main(void){
	TRISB = (TRISB | 0x000F);
	cfgUARTint();
	cfgUART2();
	EnableInterrupts();

	while(1){
		int read = (PORTB & 0x000f);
		buffer[atual%16] = read;
		addPonteiroAtual();


		// 1.5Hz
		resetCoreTimer();
		while(readCoreTimer() < 6666667);
		// 1.5Hz


	}



	return 0;
}
