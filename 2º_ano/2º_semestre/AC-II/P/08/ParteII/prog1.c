#include <detpic32.h>

#define VECTOR_TIMER1 4
#define VECTOR_TIMER2 8

volatile int c = 0;
volatile char  counter = 0;
void send2display(unsigned char value){
	static char flag = 0;	
	static const char disp7Scodes[] = {
       		 0x3F, 0x06, 0x5B, 0x4F, 0x66,  0x6D,
       		 0x7D, 0x07, 0x7F, 0x6F, 0x77,
       		 0x7C,   0x39,   0x5E,   0x79,   0x71
    	};
	
	char highValue = value >> 4;
	char lowValue = (value & 0x0F);
	LATB = LATB & 0x80FF;

	if(flag) {
		
		LATB = 	(LATB | (disp7Scodes[highValue] << 8)); 
		LATDbits.LATD5 = 0;
		LATDbits.LATD6 = 1;
	}
	else{
		
		LATB = 	(LATB | (disp7Scodes[lowValue] << 8)); 		
		LATDbits.LATD5 = 1;
		LATDbits.LATD6 = 0;
	}
	
	flag = !flag;

}


unsigned char tobcd(unsigned char value){
	return ((value /10) <<4) + (value%10);

}
int main(void){
	// Configuraçao T1 tipo A 2 Hz e T3 tipo B 25Hz com interrupções
	// T1:
	T1CONbits.TCKPS = 3;		// 256
	PR1 = 39062;			// 20M / (256 * 2) -1 

	// T2
	// K = 20M / (65536 *100) = 4 
	T2CONbits.TCKPS = 2;
	
	// PR2 = 20M  / 4 * 100 -1 = 49999  
	PR2 = 49999;
	
	// Iniciar os Timmers
	TMR1 = 0;
	TMR2 = 0;

	T1CONbits.TON = 1;
	T2CONbits.TON = 1;
	
	//Iterrupções
	
	IPC1bits.T1IP = 2;
	IEC0bits.T1IE = 1;
	IFS0bits.T1IF = 0;
	
	IPC2bits.T2IP = 2;
	IEC0bits.T2IE = 1;
	IFS0bits.T2IF = 0;
	
		
	EnableInterrupts();
	TRISD = (TRISD & 0xFF9F);
	TRISB = (TRISB & 0x80FF);
	
	while(1){
		IdleMode();
	}
	return 0;

}


void _int_(VECTOR_TIMER1) isr_T1(void){
	c++;
	if(c % 2 == 0) counter = (counter + 1) % 30;
	IFS0bits.T1IF = 0;
}
void _int_(VECTOR_TIMER2) isr_T2(void){

	send2display(tobcd(counter));
	IFS0bits.T2IF = 0;
}

