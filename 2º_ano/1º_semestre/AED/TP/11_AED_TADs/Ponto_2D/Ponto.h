#ifndef _PONTO_H_
#define _PONTO_H_


// ponto 2d atributes


typedef struct _Ponto Ponto;

//Cria um ponto 
Ponto* Ponto_initCartesianas(double x, double y);
Ponto* Ponto_initPolar(double r, double phi);
//Getters 

double Ponto_GetX(Ponto* p);
double Ponto_GetY(Ponto* p);
double Ponto_GetAngle(Ponto* p);
double Ponto_GetRadius(Ponto* p);
//Distância de dois pontos
double Ponto_Distancia(Ponto* p1, Ponto* p2);
Ponto* Ponto_GetPontoMedio(Ponto* p1, Ponto* p2);
//Distancia ao centro 
double Ponto_DistanciaAoCentro(Ponto *p);



//Printa a informação do Ponto
void Ponto_Display(Ponto* p);
void Ponto_Destroy(Ponto** p);
#endif		// _Ponto
