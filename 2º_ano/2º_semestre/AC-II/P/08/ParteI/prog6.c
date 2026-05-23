#include <detpic32.h>

#define VECTOR_TIMER3 12
#define VECTOR_TIMER1 4
int main(void){
	// Configuraçao T1 tipo A 5 Hz e T3 tipo B 25Hz com interrupções
	

	// T1:
	// K = 20M / (65536 * 5) =  61 == 64
	T1CONbits.TCKPS = 2;

	// PR1 + 1 = 20M / (64*5) = 62499
	PR1 = 62499;	

	// T2
	// K = 20M / (65536 *25) = 12 == 16 
	T3CONbits.TCKPS = 4;
	
	// PR2 = 20M  / 16 * 25 -1 = 49999  
	PR3 = 49999;
	
	// Iniciar os Timmers
	TMR1 = 0;
	TMR3 = 0;

	T1CONbits.TON = 1;
	T3CONbits.TON = 1;
	
	//Iterrupções
	
	IPC1bits.T1IP = 2;
	IEC0bits.T1IE = 1;
	IFS0bits.T1IF = 0;
	
	IPC3bits.T3IP = 2;
	IEC0bits.T3IE = 1;
	IFS0bits.T3IF = 0;
	
	// Configurar RE1 e RE3 
		
	TRISE = (TRISE & 0xFFF5);
	LATEbits.LATE1 = 0;	
	LATEbits.LATE3 = 0;
	EnableInterrupts();


	while(1){
		IdleMode();
	}
	return 0;

}


void _int_(VECTOR_TIMER1) isr_T1(void){
	while(IFS0bits.T1IF == 0);
	IFS0bits.T1IF = 0;
	LATEbits.LATE1 = !LATEbits.LATE1;
}
void _int_(VECTOR_TIMER3) isr_T3(void){

	while(IFS0bits.T3IF == 0);
	IFS0bits.T3IF = 0;
	LATEbits.LATE3 = !LATEbits.LATE3;

}
