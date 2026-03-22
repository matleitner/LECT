#int main(void)
#{
#    char c;
#    int cnt = 0;
#    while(1) {
#        c = inkey();
#        if( c == 'R' )
#            cnt = 0;
#        putChar('\r');
#        printInt(cnt, 10 | 3 << 16); // ver nota 3 na página seguinte
#        cnt = (cnt + 1) & 0xFF;
#        wait(4);
#    }
#    return 0;
#}
#void wait(int ts)
#{
#    int i;
#    for(i=0; i < 515000 * ts; i++); // wait approximately ts/10 seconds
#}
