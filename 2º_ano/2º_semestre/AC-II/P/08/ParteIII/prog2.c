#include <detpic32.h>

#define VECTOR_INT1 7 

#define VECTOR_T2 8

volatile char count = 0;
int main(void){
	// K = 20M /(65536*2) = 256  
	T2CONbits.TCKPS = 7;
	PR2 = 39062;
	TMR2 = 0;
	T2CONbits.TON = 1;
	IPC2bits.T2IP = 2;
	IEC0bits.T2IE = 1;
	IFS0bits.T2IF = 0;
	

	INTCONbits.INT1EP = 0;
	IPC1bits.INT1IP = 2;
	IFS0bits.INT1IF = 0;
	IEC0bits.INT1IE = 1;
	TRISEbits.TRISE0 = 0;
	LATEbits.LATE0 = 0;
	EnableInterrupts();

	while(1){
		IdleMode();
	}
	return 0;


}




void _int_(VECTOR_T2) isr_T2(void){
	count = (count + 1) % 6;


	if(!count & LATEbits.LATE0) LATEbits.LATE0 = 0;
	
	IFS0bits.T2IF = 0;
}
void _int_(VECTOR_INT1) isr_INT1(void){

	LATEbits.LATE0 = 1;
	IFS0bits.INT1IF = 0;
}
