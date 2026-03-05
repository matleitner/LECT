#include <detpic32.h>

int main()
{
    TRISB = TRISB & 0x80FF;  // 1000 0000 1111 1111 
    TRISD = TRISD & 0xFF9F;  // 1111 1111 1001 1111 
    LATDbits.LATD5 = 1;
    LATDbits.LATD6 = 0;
    
    
    while(1){
        int segment = 1;
        for(int=0; i<7;i++){
            
            segment = segment<<1;
        }
        LATB = 0x3000;       // 0gfe dcba 0000 0000  
    }
        return 0;
}
