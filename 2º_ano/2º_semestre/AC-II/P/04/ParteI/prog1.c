#include <detpic32.h>

void delay(unsigned int ms){
	resetCoreTimer();
	while(readCoreTimer() < 2000 * ms);

}

int main(void){
	// configure RC14 as output
	TRISCbits.TRISC14 = 0;
	while(1){
		// wait 0.5s
		delay(500);
		LATCbits.LATC14 = LATCbits.LATC14 ^ 1; // Toggle RC14 port value
	}
	return 0;
}
