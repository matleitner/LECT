#include <detpic32.h>
void _int_(27) isr_adr(void) {

	volatile adc_value;
	LATDbits.LATD11 = 0;
	adc_value = ADC1BUF0;

	LATDbits.LATD11 = 1;
	AD1CON1bits.ASAM = 1;	
	IFS1bits.AD1IF = 0;

}


int main(void){
    int N = 1;
    int x = 4;
    TRISDbits.TRISD11 = 0;
	TRISBbits.TRISB4 = 1;           // RB4 digital output disconnected
    AD1PCFGbits.PCFG4= 0;           // RB4 configured as analog input
    AD1CON1bits.SSRC = 7;           // Conversion trigger selection bits: in this
                                    // mode an internal counter ends sampling and
	

                                    // starts conversion
    AD1CON1bits.CLRASAM = 1;        // Stop conversions when the 1st A/D converter
                                    // interrupt is generated. At the same time,
                                    // hardware clears the ASAM bit
    AD1CON3bits.SAMC = 16;          // Sample time is 16 TAD (TAD = 100 ns)
    AD1CON2bits.SMPI = N-1;         // Interrupt is generated after N samples
                                    // (replace N by the desired number of
                                    // consecutive samples)
    AD1CHSbits.CH0SA = x;           // replace x by the desired input
                                    // analog channel (0 to 15)
    AD1CON1bits.ON = 1;             // Enable A/D converter
                                    // This must the last command of the A/D
       	                            // configuration sequence
	
	IPC6bits.AD1IP = 2;
	IFS1bits.AD1IF = 0;
	IEC1bits.AD1IE = 1;
	EnableInterrupts();
	
	LATDbits.LATD11 = 1;
	AD1CON1bits.ASAM = 1;               // Start conversion
    

    
	while(1){
		     

    }
    
    return 0;
}

