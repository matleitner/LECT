#include "detpic32.h"
#define VECTOR_TIMER1 4
#define VECTOR_TIMER3 12
#define VECTOR_ADC 27
    
#define IdleMode() asm volatile("wait")

volatile char voltage; 

void cfgADC(void){
    int N = 4;                      // numero de conversoes consecutivas 
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
    IPC6bits.AD1IP = 2;
    IFS1bits.AD1IF = 0;
    IEC1bits.AD1IE = 1;
}

void cfgDISPLAY(void){
    TRISB = (TRISB & 0x80FF);
    TRISD = (TRISD & 0xFF9F); 

}

void cfgTimers(){

    int k_T1 = 1;      
    int k_T3 = 2;
    PR1 = 62499;                // PRx = 20MHz / (64 * (5)) -1 =  
    PR3 = 49999;                // PRx = 20MHz / (64 * (25)) -1 =  

    T1CONbits.TCKPS = k_T1;     // 
    TMR1 = 0;                   // Clear timer T1 count register
    T1CONbits.TON = 1;          // Enable timer T1 (must be the la   

    T3CONbits.TCKPS = k_T3;        
    TMR3 = 0;                   // Clear timer T1 count register
    T3CONbits.TON = 1;          // Enable timer T1 (must be the la   


    IPC1bits.T1IP = 2;          // Interrupt priority (must be in range [1..6])
    IEC0bits.T1IE = 1;          // Enable timer T1 interrupts
    IFS0bits.T1IF = 0;          // Reset timer T1 interrupt flag

    IPC3bits.T3IP = 2;          // Interrupt priority (must be in range [1..6])
    IEC0bits.T3IE = 1;          // Enable timer T3 interrupts
    IFS0bits.T3IF = 0; 

}
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

unsigned char toBcd(unsigned char value)
{
    return ((value / 10) << 4) + (value % 10);
}

void _int_(VECTOR_TIMER1) isr_T1(void){
    
    AD1CON1bits.ASAM = 1;       
    IFS0bits.T1IF = 0;
}

void _int_(VECTOR_TIMER3) isr_T3(void){
    unsigned char hexa = toBcd(voltage);

    send2displays(hexa);

    IFS0bits.T3IF = 0;
}

void configureAll(){
    cfgADC();
    cfgDISPLAY();
    cfgTimers();
}


void _int_(VECTOR_ADC) isr_adc(void){
    int media = 0;
    int *p = (int *) (&ADC1BUF0);

    putChar('\r');
    for(; p<=(int *) (&ADC1BUF4); p+=4)
    {
        media += *p;
    }
    IFS1bits.AD1IF = 0;
    media = media / 4;
    voltage = (media * 33 + 511)/1023;
}



int main()
{

    configureAll();
    IFS0bits.T3IF = 0; // Reset timer T3 interrupt flag
    IFS0bits.T1IF = 0; // Reset timer T1 interrupt flag


    EnableInterrupts();

    while(1){
        IdleMode();
    }
    return 0;
}
