#include <detpic32.h>



volatile int value;
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


void cfgT3()
{	
	// 20 M / 1000 65535
	T3CONbits.TCKPS = 0;
	PR3 = 19999;
	TMR3 = 0;
	T3CONbits.TON = 1;
}



void cfgOC3(){
	OC3CONbits.OCM = 6;
	OC3CONbits.OCTSEL = 0;

	OC3RS = 10000;
	OC3CONbits.ON = 1;
}

void cfgADC(){
	int x = 4;
	int N = 4;
	TRISBbits.TRISB4 = 1;
	AD1PCFGbits.PCFG4= 0;
	AD1CON1bits.SSRC = 7;
	AD1CON1bits.CLRASAM = 1; // Stop conversions when the 1st A/D converter
	AD1CON3bits.SAMC = 16;
	AD1CON2bits.SMPI = N-1;
	AD1CHSbits.CH0SA = x;
	AD1CON1bits.ON = 1;


}

int main(void){
	cfgT3();
	cfgOC3();
	cfgADC();
	TRISB = (TRISB & 0x80FF);
	TRISD = (TRISD & 0xFF9F);

	TRISCbits.TRISC14 = 0;
	int counter = 0;
	while(1){
		counter = (counter + 1) % 10;
		if(counter == 0){

		
			AD1CON1bits.ASAM = 1;
			while( IFS1bits.AD1IF == 0 );
			IFS1bits.AD1IF = 0;
			int* p = (int*) (&ADC1BUF0);
			int i;
			int media  = 0;
			for(i = 0; i<4; i++){
				media += p[i*4];

			}
			value = media / 4;
			value = (value * 100 + 511) / 1023;
		
			printInt(OC3RS, 10 | 5<<16);
			putChar('\n');
		}
		if(value == 100){
			LATCbits.LATC14 = 1;		
			send2displays(0x00);

		}else{
			LATCbits.LATC14 = 0;
			send2displays(toBcd(value));
		}
		OC3RS = value * (1+ PR3);
		
		delay(10);

	}

}
