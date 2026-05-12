#include <detpic32.h>

int main(void)
{
    unsigned char segment;
    int i;    
    LATDbits.LATD5 = 0;
    LATDbits.LATD6 = 1; 


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
      LATDbits.LATD5 = !LATDbits.LATD5;
      LATDbits.LATD6 = !LATDbits.LATD6; 

    }
    

        return 0;
}


void delay(unsigned int ms){
      resetCoreTimer();

      while (readCoreTimer() < ms * 20000);
}