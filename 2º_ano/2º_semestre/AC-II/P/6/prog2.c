#include <detpic32.h>

int main(int argc, char const *argv[])
{
    volatile int aux;
    int N = 1;
    int x = 4;

    TRISDbits.TRISD11 = 0;  // cONFIGURE RD11 as a digital output port 

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
                                    // This must the last command of the A/D
                                    // configuration sequence
    
    
    while (1)
    {
        AD1CON1bits.ASAM = 1;               // Start conversion
        
        LATDbits.LATD11 = 1;                // Set LATD11 = 1

        while(IFS1bits.AD1IF == 0);         // Wait while conversion not done
        
        LATDbits.LATD11 = 0;                // RESET LATD11 = 0
        aux = ADC1BUF0;                     

        IFS1bits.AD1IF = 0;
    }
    
    return 0;
}
