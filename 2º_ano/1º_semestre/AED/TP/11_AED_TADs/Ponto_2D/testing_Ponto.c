#include "Ponto.h"

#include <stdio.h>
#include <math.h>

int main(void){
	Ponto* p1 = Ponto_initCartesianas(2, 4);
	Ponto* p2 = Ponto_initPolar(10 , M_PI/4);
	Ponto_Display(p1);
	Ponto_Display(p2);
	double dist = Ponto_Distancia(p1, p2); 
	printf("\nA distancia dos pontos é: %f\n", dist);
	
	Ponto_Destroy(&p1);
	Ponto_Destroy(&p2);
}



