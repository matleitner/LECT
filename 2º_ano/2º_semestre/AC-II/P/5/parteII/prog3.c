#include <detpic32.h>

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

void delay(unsigned int ms){
    resetCoreTimer();
    while (readCoreTimer() < ms * 20000  );

}

unsigned char toBcd(unsigned char value)
{
    return ((value / 10) << 4) + (value % 10);
}

int main(void)
{
    int counter = 0;
    char hexa;
    int freqIncremento = 50;    // 1 / 5 = 0.500 s = 50 ms 

    TRISBbits.TRISB0 = 1;

    // configure RB8-RB14 as outputs
    TRISB = (TRISB & 0x80FF);
    // configure RD5-RD6 as outputs
    TRISD = (TRISD & 0x9F);
    while(1)
    {
        if(PORTBbits.RB0)
        hexa = toBcd(counter);
        int i = 0;
        do {

            send2displays(hexa);
            // wait 100Hz 1 / 100 = 0.100 = 10ms
            delay(10);

        } while(++i <  freqIncremento);
        if(PORTBbits.RB0) counter = (counter +1 ) % 60;
        else{
            counter = (counter - 1 + 60) % 60;
        }
    }   
}

// 0001 0101