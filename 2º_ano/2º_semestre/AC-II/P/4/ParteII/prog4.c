#include <detpic32.h>

int main(void)
{
    unsigned char segment;
    int i;    
    LATD = (LATD & 0x6F) | 0x20;

    TRISB = TRISB & 0x80FF;        // 1000 0000
    TRISD = TRISD & 0xFFCF;   

 
    while (1)
    {
      segment = 1;
      for(i = 0; i<7; i++){
          LATB = segment << 8;;
          delay(500);
          segment = segment << 1;
      }
    }
    
    LATD ^= 0x60;

    return 0;
}


void delay(unsigned int ms){
    resetCoreTimer();

    while (readCoreTimer() < ms * 20000);
}