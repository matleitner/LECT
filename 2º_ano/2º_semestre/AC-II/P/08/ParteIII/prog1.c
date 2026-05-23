#include <detpic32.h>

void delay(unsigned int ms){

	resetCoreTimer();
	while(readCoreTimer() < ((PBCLK/1000) * ms));


} 

int main(void){

	TRISDbits.TRISD8 = 1;
	TRISEbits.TRISE0 = 0;
	int button;
	LATEbits.LATE0 = 0;
	

	while(1){
		button = PORTDbits.RD8;

		if(!button){

			LATEbits.LATE0 = 1;
			
			delay(5000);
		
			LATEbits.LATE0 = 0;
		}
			

		
	}
	

	return 0;
}
