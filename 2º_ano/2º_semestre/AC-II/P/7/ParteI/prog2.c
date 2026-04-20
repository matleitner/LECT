#include <detpic32.h>



void send2displays(unsigned char value)
{   static char displayFlag = 0;
    static const char disp7Scodes[16] = {0x3F, 0x06,0x5b,   0x4F,  0x66,  0x6D,  0x7D,  0x07,  0x7F,0x6F, 0x77,
          0x7C,   0x39,   0x5E,   0x79,   0x71};
    
    // select display high
    // send digit_high (dh) to display:
    int digit_high = value >> 4;
    int digit_low = value & 0x0F;
    if(!displayFlag)
    {
        LATD = (LATD & 0x9F) | 0x20;
        LATB = (LATB & 0x80FF ) | (disp7Scodes[digit_low] << 8);
    }
    else{
        LATD = (LATD & 0x9F) | 0x40;
        LATB = (LATB & 0x80FF) | (disp7Scodes[digit_high] << 8 );
    }
    displayFlag = !displayFlag;
    // select display low
    // send digit_low (dl) to display:
}

void wait(unsigned int ms){
    resetCoreTimer();
    while (readCoreTimer() < ms * 20000  );

}

unsigned char toBcd(unsigned char value)
{
    return ((value / 10) << 4) + (value % 10);
}

volatile unsigned char voltage = 0; // Global vairable



int main(void){
	 TRISB = (TRISB & 0x80FF);
    // configure RD5-RD6 as outputs
 	 TRISD = (TRISD & 0x9F);
	unsigned int cnt = 0;
	int N = 8;
    int x = 4;
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
	

    

    
	while(1){
		if( cnt == 0) {
			AD1CON1bits.ASAM = 1;               // Start conversion
		}	     
		send2displays(toBcd(voltage));

		cnt = (cnt + 1) % 20;
		wait(10);
    }
    
    return 0;
}


void _int_(27) isr_adr(void) {
	int i;
	int media = 0;
	int* p = (int*) (&ADC1BUF0);

	for(i = 0; i<8; i++){
		media += p[i*4];
	}
	media = media/8;
	voltage = (media * 33 + 511) /1023;

	AD1CON1bits.ASAM = 1;	
	IFS1bits.AD1IF = 0;

}
