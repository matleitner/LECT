#include "detpic32.h"
volatile unsigned int count = 0;

void _int_(12) isr_T3(void){
    count++;
    if(count % 2 == 0){
        putChar('.');
    }

    IFS0bits.T3IF = 0;
}

int main(void)
{
    // Configure Timer T3 (2 Hz with interrupts disabled)


    T3CONbits.TCKPS = 7;        // 1:32 prescaler (i.e. fout_presc = 625 KHz)
    PR3 = 39061;                // Fout = 20MHz / (32 * (62499 + 1)) = 10 Hz 
    TMR3 = 0;                   // Clear timer T2 count register
    T3CONbits.TON = 1;          // Enable timer T2 (must be the la   

    IPC3bits.T3IP = 2; // Interrupt priority (must be in range [1..6])
    IEC0bits.T3IE = 1; // Enable timer T2 interrupts
    IFS0bits.T3IF = 0; // Reset timer T2 interrupt flag
    EnableInterrupts();
    while(1)
    {
    }
    return 0;
}