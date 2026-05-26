#include <detpic32.h>
void cfgUART2(){

	U2MODEbits.BRGH = 0; 
	int baudrate = 1200;
	U2BRG = (PBCLK + 8 *baudrate)/(16*(baudrate)) -1;
	
	U2MODEbits.PDSEL = 0;
	U2MODEbits.STSEL = 0;

	U2STAbits.UTXEN = 1;
		
	U2MODEbits.ON = 1;
}
void putc(char c){
	while(U2STAbits.UTXBF == 1);
	U2TXREG = c;

}

void wait(unsigned int ms){

	resetCoreTimer();
	while(readCoreTimer() < (ms * PBCLK / 1000));
}

void putstr(char* string){
	while(*string != '\0'){
		putc(*string);
		string++;
	}
}

int main(void){
	TRISB = (TRISB | 0x000F);
	cfgUART2();
	char* string = "RB30=";
	int key[4];
	while(1){
		int i;
		int val = (PORTB & 0x0F);
		for(i = 0; i<4;i++){
			key[i] = ((val >> i)) & 0x01;

		}
		putstr(string);
		for(i = 3; i>=0; i--){
			putc((char)(key[i] + '0'));
		}
		putc('\n');
		wait(500);
	}
	

	return 0;
}
