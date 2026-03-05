#include <detpic32.h>

int main(int argc, char const *argv[])
{
    TRISE = 0xFFFE;
    
    while(1){
        LATE = 0x0001;
    }
    return 0;
}
