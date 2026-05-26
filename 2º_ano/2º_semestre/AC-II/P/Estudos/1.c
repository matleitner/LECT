#include <detpic32.h>
volatile int val = 50;
void cfgOC2(){

	OC2CONbits.OCM= 6;
	OC2CONbits.OCTSEL = 0;
	OC2RS = (val * PR2) / 100;
	OC2CONbits.ON = 1;

}

void cfgT2(){
	// 20M / 65536 / 150
	T2CONbits.TCKPS = 2; 
	PR2 = 33332; 
	TMR2 = 0;
	T2CONbits.TON = 1;


}
void cfgSwitches(){
	TRISB = (TRISB | 0xF);
	


}
int main(void) {
	int value;
	cfgSwitches();
	cfgT2();
	cfgOC2();
	while(1){
		value = (PORTB & 0xF);

		if(value == 1)
		{
			val = 25;
			OC2RS = (val * PR2) / 100;
		}else if(value == 2){

		val = 70;
		OC2RS = (val * PR2) / 100;	
		}
		printInt(OC2RS, 10 | 3 << 16);
		putChar('\n');
		resetCoreTimer();
		while(readCoreTimer() < (25* PBCLK /(100 * 1000)));

		
	}
	return 0;
}
