#include <stdio.h>
#include <math.h>

int main(void){
	
	int maiorAngulo;
	int menorAngulo;
	int espacamento;

	
	printf("Indique o menor valor do angulo: ");
	scanf("%d", &menorAngulo);
	

	
	printf("Indique o mmaior valor do angulo: ");
	scanf("%d", &maiorAngulo);
	
	
	printf("Espaçamento: ");
	scanf("%d", &espacamento);

	
	
	printf("%3s %5s %5s\n","ang","sin(ang)","cos(ang)");
	printf("%3s %6s %5s\n","---","--------","--------");	
	
	
	for(int ang = menorAngulo; ang<=maiorAngulo; ang +=espacamento){
		double rad = M_PI * ang /180.0;

		
		double cosAng = cos(rad);
		double sinAng = sin(rad);

		printf("%3d %6.2f %8.2f\n",ang,sinAng,cosAng);	
		

	}
	return 0;
}
