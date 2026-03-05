#include <detpic32.h>

int main()
{
    TRISB = TRISB & 0x80FF;  // 1000 0000 1111 1111 
    TRISD = TRISD & 0xFF9F;  // 1111 1111 1001 1111 

    
    
    while(1){
        LATDbits.LATD5 = 1;
        LATDbits.LATD6 = 0;
        char c = getchar();
        if(c >= 'a' && c<= 'g'){
            c = c - 'a';
            LATB = (LATB & 0x80FF) | (1 << (c + 8));
        }
    }
    
    return 0;
}
