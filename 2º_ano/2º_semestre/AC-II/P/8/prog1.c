#include "detpic32.h"


int main(void)
{
    // Configure Timer T3 (2 Hz with interrupts disabled)
    /*f_out = (f_PBCLK / K / 65535+ 1 )
    k = f_PBCLK / f_out * (PR3 +1)
    K = 20 *10⁶ / 2 * 65536  =153
    */
    T3CONbits.TCKPS = 7;        // 1:32 prescaler (i.e. fout_presc = 625 KHz)
    PR3 = 39061;                // Fout = 20MHz / (32 * (62499 + 1)) = 10 Hz 
    TMR3 = 0;                   // Clear timer T2 count register
    T3CONbits.TON = 1;          // Enable timer T2 (must be the la    
    while(1)
    {
        // Wait while T3IF = 0
        while(IFS0bits.T3IF == 0);
        // Reset T3IF
        IFS0bits.T3IF = 0;
        putChar('.');
    }
    return 0;
}