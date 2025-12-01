#include "Ponto.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Constructor 
struct _Ponto{
	double x;
	double y;

};
Ponto* Ponto_initCartesianas( double x, double y){
	Ponto* p =(Ponto*)malloc(sizeof(Ponto));
	p->x = x;
	p->y = y;
	return p;
}
Ponto* Ponto_initPolar(double radius, double angle){
	Ponto* p = malloc(sizeof(Ponto));
	p->x = radius * cos(angle);
	p->y = radius * sin(angle);	
	return p;
}

//Getters 

double Ponto_GetX(Ponto* p){ return p->x; }
double Ponto_GetY(Ponto* p){ return p->y; }
double Ponto_GetRadius(Ponto* p){ return   sqrt(pow(p->x,2) + pow(p->y,2)); }
double Ponto_GetAngle(Ponto* p){ return acos(p->x/sqrt(pow(p->x,2) + pow(p->y,2))); }

//Funções aplicada a pontos 

double Ponto_Distancia(Ponto* p1, Ponto* p2){
	return sqrt(pow(Ponto_GetX(p1)-Ponto_GetX(p2),2) + pow(Ponto_GetY(p1)-Ponto_GetY(p2),2));
}
double Ponto_DistanciaAoCentro(Ponto* p){
	return sqrt(pow(Ponto_GetX(p),2) + pow(Ponto_GetY(p),2));
}

Ponto* Ponto_GetPontoMedio(Ponto* p1, Ponto* p2){
	double x = (Ponto_GetX(p1) + Ponto_GetX(p2))/2.0;
	double y = (Ponto_GetY(p1) + Ponto_GetY(p2))/2.0;
	
	return Ponto_initCartesianas(x, y);
}
void Ponto_Display(Ponto* p){
	printf("\nInfos do Ponto:\nRadius: %f, angle (rad): %f; P", Ponto_GetRadius(p), Ponto_GetAngle(p));
	printf("(%f,%f)\n",Ponto_GetX(p) , Ponto_GetY(p));
}

void Ponto_Destroy(Ponto** p){
	free(*p);
	*p = NULL;

}
