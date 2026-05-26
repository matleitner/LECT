#include <detpic32.h>
volatile int grau = 0;
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

void delay(unsigned int ms){
    resetCoreTimer();
    while (readCoreTimer() < ms * 20000  );

}

unsigned char toBcd(unsigned char value)
{
    return ((value / 10) << 4) + (value % 10);
}

void cfgADC1(){
	int x = 4;
	int N = 2;

	TRISBbits.TRISB4 = 1;
	AD1PCFGbits.PCFG4= 0;
	AD1CON1bits.SSRC = 7;
	// RBx digital output disconnected
	// RBx configured as analog input
	// Conversion trigger selection bits: in this
	// mode an internal counter ends sampling and
	// starts conversion
	AD1CON1bits.CLRASAM = 1; // Stop conversions when the 1st A/D converter
	// interrupt is generated. At the same time,
	// hardware clears the ASAM bit
	AD1CON3bits.SAMC = 16;
	// Sample time is 16 TAD (TAD = 100 ns)
	AD1CON2bits.SMPI = N-1;
	// Interrupt is generated after N samples
	// (replace N by the desired number of
	// consecutive samples)
	AD1CHSbits.CH0SA = x;
	// replace x by the desired input
	// analog channel (0 to 15)
	AD1CON1bits.ON = 1;


}
void cfgT2(void){

	// timer2
	// 20M / 65536 / 120 = 2.54
	//
	T2CONbits.TCKPS = 2;
	TMR2 = 0;
	PR2 = 41665;		// K = 4;
	T2CONbits.TON = 1;
	// Interrupts
	IPC2bits.T2IP = 2;
	IFS0bits.T2IF = 0;
	IEC0bits.T2IE = 1;
}


void _int_(8) isr_T2(void){

	send2displays(toBcd(grau));
	IFS0bits.T2IF = 0;

}
int main(void){
	int N = 2;
	cfgT2();
	cfgADC1();
	TRISB = TRISB & 0x80FF;
	TRISD = TRISD & 0xFF9F;
	EnableInterrupts();
	while(1){

		AD1CON1bits.ASAM = 1;
		while(IFS1bits.AD1IF == 0);
		

		
		int* p = (int*) (&ADC1BUF0);
		int i;
		int media = 0;
		for(i = 0; i<N; i++){
			media += p[i*4];
		}
	
		media = media/N;
	
		grau = ((media * 50 + 511) / 1023) +15 ;
		
		IFS1bits.AD1IF = 0;
		resetCoreTimer();
		while(readCoreTimer() < ((PBCLK / 1000) * 100)); 
	}



	return 0;
}
