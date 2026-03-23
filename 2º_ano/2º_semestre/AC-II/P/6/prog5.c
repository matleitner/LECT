#include <detpic32.h>

int main(void)
{   

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
                                    // This must the last command of the A/D
                                    // configuration sequence

    while(1){
        unsigned int i, time;
        AD1CON1bits.ASAM = 1;               // Start conversion
        resetCoreTimer();
        while(IFS1bits.AD1IF == 0);         // Wait while conversion not done
        time = readCoreTimer();
        
        
		int media = 0;
        int *p = (int *) (&ADC1BUF0);


/*
        for( i = 0; i<16; i++) {
            
        printInt(p[i*4], 16 | 3 << 16);
        putChar(' ');
        }
*/  
        putChar('\r');
        for(; p<=(int *) (&ADC1BUF4); p+=4)
        {
            media += *p;
        }
       	
		media = media / 4;
        int volts = (media * 33 + 511)/1023;

        printStr("Média ADC: ");
        printInt(media, 10 | 3 << 16);
        
		putChar('\n');
        printStr("Voltagem correspondente: ");
        printInt(volts, 10 | 3 << 16);
		putChar('\r');
        
        
        IFS1bits.AD1IF = 0;
        

    }
    
    return 0;
}
