/*
K = 20 *10⁶ / 5 * 65536  = 61... 
K = 20 *10⁶ / 25 * 65536  = 12...

*/

#include "detpic32.h"
#define VECTOR_TIMER1 4
#define VECTOR_TIMER3 12
#define IdleMode() asm volatile("wait")


void _int_(VECTOR_TIMER1) isr_T1(void)
{
    // print character '1'

    LATDbits.LATD0 = !LATDbits.LATD0; 
    // Reset T1IF flag
    IFS0bits.T1IF = 0;

}
void _int_(VECTOR_TIMER3) isr_T3(void)
{
    // print character '3'
    LATDbits.LATD2 = !LATDbits.LATD2;
    // Reset T3IF flag
    IFS0bits.T3IF = 0;
}

int main(void)
{
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD2 = 0;
    LATDbits.LATD0 = 0;
    LATDbits.LATD2 = 0;
    
    
    int k_T1 = 2;      // 64
    int k_T3 = 6;
    // Configure Timer T3 (2 Hz with interrupts disabled)


    T1CONbits.TCKPS = k_T1;     // 
    PR1 = 62499;                // PRx = 20MHz / (64 * (5)) -1 =  
    TMR1 = 0;                   // Clear timer T1 count register
    T1CONbits.TON = 1;          // Enable timer T1 (must be the la   

    T3CONbits.TCKPS = k_T3;        
    PR3 = 12499;                // PRx = 20MHz / (64 * (25)) -1 =  
    TMR3 = 0;                   // Clear timer T1 count register
    T3CONbits.TON = 1;          // Enable timer T1 (must be the la   


    IPC1bits.T1IP = 2;          // Interrupt priority (must be in range [1..6])
    IEC0bits.T1IE = 1;          // Enable timer T1 interrupts
    IFS0bits.T1IF = 0;          // Reset timer T1 interrupt flag

    IPC3bits.T3IP = 2;          // Interrupt priority (must be in range [1..6])
    IEC0bits.T3IE = 1;          // Enable timer T3 interrupts
    IFS0bits.T3IF = 0;          // Reset timer T3 interrupt flag

    EnableInterrupts();
    while(1)
    {
        IdleMode();
    }
    return 0;
}