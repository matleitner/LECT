#include <detpic32.h>
#define VECTOR_T2 8
#define VECTOR_T1 4
#define VECTOR_ADC 27
volatile char counter = 0;
void wait(unsigned int ms){
	resetCoreTimer();
	while(readCoreTimer() < (ms * (PBCLK / 1000)));

} 



void setFrequencyT1(unsigned int freq){
	if(freq > 0) {
		PR1 = (20000000 / (256 * freq)) -1;
	}

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
	unsigned char val = ((counter / 10)<<4) + (counter%10);	
	send2disp(val);
	printInt(counter, 16 | 4 << 16);
	putChar('\r');
	IFS0bits.T2IF = 0;

}



void _int_(VECTOR_T1) isr_T1(void){
	
	counter = (counter + 1) % 100;
	IFS0bits.T1IF = 0;

}
void _int_(VECTOR_ADC) isr_ADC(void){
	
	int i;
	int media = 0;
	int* p = (int*)(&ADC1BUF0);
	for(i = 0; i< 4;i++){
		media += p[i*4];

	}	
	media = media / 4;

	int voltage = (media * 1023 + 511) / 1023;
//	printInt(voltage, 10 | 4<<4);
	setFrequencyT1(1+voltage/127) ;
	AD1CON1bits.ASAM = 0;
	IFS1bits.AD1IF = 0;

}
void cfgT2(){
	// 20M / (50*65536)
	T2CONbits.TCKPS = 3;
	PR2 = 49999;
	TMR2 = 0;
	T2CONbits.TON = 1;

	IEC0bits.T2IE = 1;
	IPC2bits.T2IP = 2;
	IFS0bits.T2IF = 0;

}

void cfgT1(){

	// Tipo A 1 8 64 256
	// 20M / 10/65536
	T1CONbits.TCKPS = 7;
	PR1 = 7811;
	TMR1 = 0;
	T1CONbits.TON = 1;

	IEC0bits.T1IE = 1;
	IPC1bits.T1IP = 2;
	IFS0bits.T1IF = 0;
}
void cfgTRIS(){

	TRISB = (TRISB & 0x80FF);
	TRISD = (TRISD & 0xFF9F);

}
void cfgADC(){
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
	AD1CON2bits.SMPI = 4-1;
	// Interrupt is generated after N samples
	// (replace N by the desired number of
	// consecutive samples)
	AD1CHSbits.CH0SA = 4;
	// replace x by the desired input
	// analog channel (0 to 15)
	AD1CON1bits.ON = 1;
	IPC6bits.AD1IP = 2;
	IFS1bits.AD1IF = 0;
	IEC1bits.AD1IE = 1;


}



int main(void){
	int prev_value; 
	
	cfgT1();
	cfgT2();
	cfgTRIS();
	cfgADC();
	EnableInterrupts();
	while(1){

		AD1CON1bits.ASAM = 1;
		wait(250);

		char c = inkey();

		if(c >= '0' && c<= '4'){
			int value = (int) (c - '0');
			if(prev_value != value){
				prev_value = value;
				int freq = 2 * (1 + value);
				setFrequencyT1(freq);
				
				printStr("Nova frequencia: ");
				printInt(value, 10 | 2 << 4);
				printStr("Hz \n");



			}
			

		}
		
		

	}

	return 0;
}
