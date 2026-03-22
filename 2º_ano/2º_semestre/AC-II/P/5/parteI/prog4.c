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
        LATB = (LATB & 0x80FF) | (digit_low << 8);
    } else{
        LATD = (LATD & 0xFF9F) | 0x0040;
        LATB = (LATB & 0x80FF) | (digit_high << 8);
    }
    displayFlag = !displayFlag;
}

void wait(unsigned int ms){
    resetCoreTimer();
    while(readCoreTimer()< ms * 20000);
}

int main(void)
{
    // configure RB8-RB14 as outputs
    TRISB = (TRISB & 0x80FF);
    // configure RD5-RD6 as outputs
    TRISD = (TRISD & 0xFF9F);

    while(1){
        send2displays(0x15);
        // 20Hz → 1/20 = 50 ms
        //wait(50);
        // 50Hz → 1/50 = 20 ms
        //wait(20);
        // 100Hz → 1/100 = 10 ms
        wait(10);
    }
    return 0;
}