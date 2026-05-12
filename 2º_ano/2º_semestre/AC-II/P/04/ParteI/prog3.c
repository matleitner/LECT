#include <detpic32.h>


int main()
{   
    // bits 6 a 3 de TRISE como saída
    TRISE = TRISE & 0xFF87;
    int counter = 0;
    int step = 1;

    int clockTicks = 1 / 2.7 * PBCLK;
    while (1)
    {
        
        LATE = (LATE & 0Xff87) | counter << 3;
        
        resetCoreTimer(); while(readCoreTimer()< clockTicks);
    
        counter = (counter - step + 10) % 10;
    }
    
    return 0;
}
