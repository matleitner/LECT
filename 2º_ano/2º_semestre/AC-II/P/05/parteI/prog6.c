#include <detpic32.h>

void send2displays(unsigned char value)
{

    static const char disp7Scodes[16] = {0x3F, 0x06,0x5b,   0x4F,  0x66,  0x6D,  0x7D,  0x07,  0x7F,0x6F, 0x77,
          0x7C,   0x39,   0x5E,   0x79,   0x71};
    static char displayFlag = 0;                // static variable: doesn't loose its
                                                // value between calls to function
    int digit_low = value & 0x0F;
    int digit_high = value >> 4;

    if (displayFlag == 0){
        LATD = (LATD & 0xFF9F) | 0x0020;
        LATB = (LATB & 0x80FF) | (disp7Scodes[digit_low]  << 8);
    } else{
        LATD = (LATD & 0xFF9F) | 0x0040;
        LATB = (LATB & 0x80FF) | (disp7Scodes[digit_high] << 8);
    }
    displayFlag = !displayFlag;
}

void wait(unsigned int ms){
    resetCoreTimer();
    while(readCoreTimer()< ms * 20000);
}


int main(void)
{
    int i;
    int counter = 0;
    TRISB = (TRISB & 0x80FF);
    TRISD =(TRISD & 0xFF9F);
    i = 0;
    unsigned int t = 10;
    int N = 200 / t;
    while(1){
        // FORMA B 
        send2displays(counter);
        wait(t);
        i = (i + 1) % N;
        if(i == 0)
            counter = (counter+1) & 0xFF;

    }
    return 0;
}
