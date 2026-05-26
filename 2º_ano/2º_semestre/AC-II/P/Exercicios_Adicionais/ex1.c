#include <detpic32.h>

volatile unsigned char value = 0;
#define VECTOR_T2 8


void wait(unsigned int ms){
	resetCoreTimer();
	while(readCoreTimer() < (ms * (PBCLK / 1000)));

} 
unsigned char toBCD(char byte){
	
	return ((byte/10)<<4) + (byte % 10);

}

void send2disp(unsigned char byte){
	static int flag = 0;
	    static const char disp7Scodes[16] = {0x3F, 0x06,0x5b,   0x4F,  0x66,  0x6D,  0x7D,  0x07,  0x7F,0x6F, 0x77,
          0x7C,   0x39,   0x5E,   0x79,   0x71};

	int lowDigit = byte & 0xF;
	int highDigit = byte >> 4;
	
	if(!flag){
		LATDbits.LATD5 = 0;
		LATDbits.LATD6 = 1;
		
		LATB = 	(LATB & 0x80FF) | ( disp7Scodes[highDigit] << 8);

	} else {

		
		LATDbits.LATD5 = 1;
		LATDbits.LATD6 = 0;
		
		LATB = 	(LATB & 0x80FF) | ( disp7Scodes[lowDigit] << 8);
	}		
	
	flag = !flag;

}



void _int_(VECTOR_T2) isr_T2(void){
	
	send2disp(toBCD(value));
	
	IFS0bits.T2IF = 0;

}


void cfgTimer2(){
	// 20M / (100*65536)
	T2CONbits.TCKPS = 2;
	PR2 = 49999;
	TMR2 = 0;
	T2CONbits.TON = 1;

	IEC0bits.T2IE = 1;
	IPC2bits.T2IP = 2;
	IFS0bits.T2IF = 0;

}

void cfgLeds(){

	TRISE = (TRISE & 0xFFF0);

}

int main(void){
	TRISB = (TRISB & 0x80FF);
	TRISD = (TRISD & 0xFF9F);
	cfgLeds();
	cfgTimer2();
	int standBy = 1;	
	EnableInterrupts();
	value = 0xFF;
	while(1){
		char c = inkey();
		if(c == 0) continue;
		if(c >= '0' && c <= '3') {
            		value = c - '0'; // Converte o ASCII para o valor numérico real (ex: '5' - '0' = 5)
			LATE = (LATE & 0xFFF0 )| (1<< value);
       		} else {
			LATE = (LATE | 0xf);
			value = 0xff;
			wait(1000);
			LATE = LATE & 0xFFF0;
		 	LATB = LATB & 0x80FF;

		}	
	
		
	}
}
