#include "detpic32.h"
#define VECTOR_TIMER1 4
#define VECTOR_TIMER3 12
#define VECTOR_ADC 27
    


volatile char voltage; 
void cfgOC1(void){
	// Configurar módulo OC1 
	OC1CONbits.OCM = 6;
	OC1CONbits.OCTSEL = 1;			// selecionar o T3
	
	OC1RS = ((PR3 + 1) * 25) / 100;
	OC1CONbits.ON = 1;

}

void cfgTimers(){
    // K_presc = 20Mhz / (65536 * 100) = 3.05 = 4
    int k_T3 = 2;
    PR3 = 49999;                // PRx = 20MHz / (4 * (100)) -1 =  
    T3CONbits.TCKPS = k_T3;        
    TMR3 = 0;                   // Clear timer T1 count register
    T3CONbits.TON = 1;          // Enable timer T1 (must be the la   
    IPC3bits.T3IP = 2;          // Interrupt priority (must be in range [1..6])
    IEC0bits.T3IE = 1;          // Enable timer T3 interrupts
    IFS0bits.T3IF = 0; 
}


void _int_(VECTOR_TIMER3) isr_T3(void){
    IFS0bits.T3IF = 0;
}

void configureAll(){
    cfgTimers();
    cfgOC1();	
}
void setPWM(unsigned int dutyCycle){
	if(dutyCycle<0 || dutyCycle>100){
		return;
	}

	OC1RS = ((PR3 + 1) * dutyCycle) / 100;
}
int main(void)
{

    configureAll();
    IFS0bits.T3IF = 0; // Reset timer T3 interrupt flag
    IFS0bits.T1IF = 0; // Reset timer T1 interrupt flag
    // 4)
    setPWM(80);
    // 5)
    TRISCbits.TRISC14 = 0;
    TRISDbits.TRISD0 = 1;

    while(1){
	LATCbits.LATC14 = PORTDbits.RD0;
    }
    return 0;
}

