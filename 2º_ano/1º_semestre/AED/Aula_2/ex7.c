#include <stdio.h>
#include <assert.h>
#include <math.h>


// The coefficients of a degree n polynomial
// are stored in an array p of size (n + 1)
// p[0] is the coefficient of the largest degree term
// p[n] is the coefficient of the zero-degree term
// Display a polynomial
// Pre-Conditions: coef != NULL and degree >= 0
// Example of produced output:
// Pol(x) = 1.000000 * x^2 + 4.000000 * x^1 + 1.000000
void DisplayPol(double *coef, size_t degree);

// Compute the value of a polynomial using Horner’s method:
// Pre-Conditions: coef != NULL and degree >= 0
//double ComputePol(double* coef, size_t degree, double x) { ... }
// Test example:
// Pol(x) = 1.000000 * x^2 + 4.000000 * x^1 + 1.000000
// Pol(2.000000) = 13.000000

double ComputePol(double *coef, size_t degree, double x);
// Compute the real roots, if any, of a second-degree polynomial
// Pre-Conditions: coef != NULL and degree == 2 and coef[0] != 0
// Pre-Conditions: root_1 != NULL and root_2 != NULL
// Return values: 0 -> no real roots
// 1 -> 1 real root with multiplicity 2
// 2 -> 2 distinct real roots
// The computed root values are returned via the root_1 and root_2
// pointer arguments
// Assign 0.0 to the *root_1 and *root_2 if there are no real roots
unsigned int GetRealRoots(double* coef, size_t degree, double* root_1, double* root_2);



int main(){
	double coef[] = {4,5,1,4,1}; // 4 x^4 + 5x^3 + x^2 + 4 x +1
	size_t degree = 4;
	double x = 2;
	DisplayPol(coef,degree);

	double f_x = ComputePol(coef, degree, x);
	printf("Pol(%f) = %f\n",x,f_x);
	
	double root_1;
	double root_2;
	double parabola[] = {1,4,1};
	size_t grau = 2;
	unsigned int roots = GetRealRoots(parabola , grau , &root_1, &root_2);
	printf("a parabola: ");
        DisplayPol(parabola,grau);
 	printf("Tem %d raizes\n", roots);
	printf("root : %f\n", root_1);
	if(  root_2 != root_1) {printf("root : %f\n",root_2);}
	return 0;
}




void DisplayPol( double *coef, size_t degree){
	assert(coef !=NULL && degree>=0); 
	printf("Pol(x) = ");
	for (int i= 0; i< degree; i++){
		if(coef[i] == 1) 
			printf("x^%ld +  ",degree-i);
		else{
		if(coef[i] != 0)printf("%f * x^%ld + ", coef[i], degree-i);
		}
	}

	if(coef[degree] != 0)printf("%f\n",coef[degree]);

}

double ComputePol(double *coef, size_t degree, double x){
	assert( coef != NULL && degree>=0);

	double f_x =coef[0];

	for(int i = 1; i<=degree;i++){
		
		f_x = f_x*x + coef[i];

	
	}
	return f_x;
	



}

unsigned int GetRealRoots(double* coef, size_t degree, double* root_1, double* root_2){
 
	assert(coef!=NULL && degree == 2 && coef[0] !=0);
	assert(root_1 != NULL && root_2 !=NULL);

	double delta = (coef[1]*coef[1])-(4*coef[2]*coef[0]);

	if(delta<0){
		*root_1 = 0;
		*root_2 = 0;
		return 0.0;
	}
		
	else if(delta == 0)
		{
		*root_1 = (-coef[1] )/(2*coef[0]);	
		*root_2 = *root_1;
		return 1.0;
		}
	else{
		*root_1 = (-coef[1] + sqrt(delta))/(2*coef[0]);
        	*root_2 = (-coef[1] - sqrt(delta))/(2*coef[0]);
		return 2.0;
		}


}
