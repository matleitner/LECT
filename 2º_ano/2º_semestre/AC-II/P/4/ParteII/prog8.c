#include <detpic32.h>

int main(void)
{
    static const char disp7Scodes[] = {
        // 0 - 9
        0x3F, 0x06, 0x5B, 0x4F, 0x66,  0x6D,
        0x7D, 0x07, 0x7F, 0x6F, 0x77,
        // A - F 
        0x7C,   0x39,   0x5E,   0x79,   0x71
    };

    int dips, code;
    
    // configure RB0 to RB3 as inputs
    // configure RB8 to RB14 and RD5 to RD6 as outputs
    //    RB8 to RB14 →↓↓ ↓← RB0 to RB3 
    TRISB = (TRISB & 0x80F0) | 0x000F;

    TRISD = TRISD & 0xFF9F;

    // Select display high
    LATD = (LATD & 0xFF9F) | 0x0020;           // 1 **0** **1** 1      

    while(1)
    {
        dips = PORTB & 0x000F;      // read dip-switch (bits 3-0)
        code = disp7Scodes[dips];   // convert to 7 segments code
        LATB = (LATB & 0x80FF)  | (code << 8);   // send code to display
    }
    return 0;
}