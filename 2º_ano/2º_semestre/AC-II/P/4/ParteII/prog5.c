#include <detpic32.h>

int main(void)
{
    unsigned char segment;
    int i;
    unsigned int freq;
    
    LATD = (LATD & 0x6F) | 0x20;

    TRISB = TRISB & 0x80FF;        // 1000 0000
    TRISD = TRISD & 0xFFCF;   
    freq = 1/10*1000;
    //freq = 1/50*1000;
    //freq = 1/100*1000;
 
    while (1)
    {
      segment = 1;
      for(i = 0; i<7; i++){
          LATB = segment << 8;;
          delay(freq);
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