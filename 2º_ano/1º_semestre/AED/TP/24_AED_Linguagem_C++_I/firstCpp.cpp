#include <iostream>
#include <math.h>
#include <iomanip>
// en.cppreference.com/w
using namespace std;


template <typename JORDAN>
int compare(JORDAN a, JORDAN b){

	return (a<b) ? -1 : 1;
}


//Formatação

void do_it(int N){

	cout << " n N*n			sqrt(n)\n"
		 << "-- --- ----------------------\n";

	for(int i = 1; i <= N; i++){
		cout << setw(2) << i 
			 << " "
			 << setw(3) << i*i
			 << " " 
			 << fixed << setw(17) << setprecision(15) << sqrt((double)i)
			 << endl;
		

	}

}


int main(void) {

	cout << "Hello world!" << endl;		// std::cout << "String" << std::endl ou "String\n"	
	int n = 0;

	std::cout << "Enter an integer value :";
	std::cin >> n;

	for(int i = 1; i<=n;++i){

		std::cout << i << std::endl;

	}
	
//	do_it(n);



	


	


	return 0;


}
