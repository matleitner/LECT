#include <stdio.h>
#include <math.h>


int main(void){
	const int size = 3;
	int array_potencias[size];
	
	for(int x =1;x<=9;x++){
		for(int y = 0; y<=9; y++){
		
			for(int z = 0; z<=9;z++){
				array_potencias[0] = x*x*x;
				array_potencias[1] = y*y*y;
				array_potencias[2] = z*z*z;
						
				if(array_potencias[0] + array_potencias[1] + array_potencias[2] == x*100 + y*10 + z)printf("%d%d%d\n",x,y,z);
				}
				}
		}

		return 0;

}
