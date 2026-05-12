
int main(void){
	int cnt1  = 0;
	int cnt5  = 0;
	int cnt10 = 0;

	while(1){
		putChar('\r');
		delay(100);
		cnt1++;
		if(cnt1%10 == 0) cnt10++;
		if(cnt1%5 == 0) cnt5++;
		printInt(cnt1, 10 | 5 << 16);
		printInt(cnt5, 10 | 5 << 16);
		printInt(cnt10, 10 | 5 << 16);
		
		
	}



}
