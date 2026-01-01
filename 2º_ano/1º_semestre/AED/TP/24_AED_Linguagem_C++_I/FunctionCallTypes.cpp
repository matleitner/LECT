//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// J. Madeira --- February 2022
//
// Adapted from the I. Horton examples
//

#include <iostream>

double ChangeItByValue(double it) {
  it += 10.0;
  std::cout << "Within function, it = " << it << std::endl;
  return it;
}

double ChangeItByPointer(double* p) {
  *p += 10.0;
  std::cout << "Within function, *p = " << *p << std::endl;
  return *p;
}

double ChangeItByReference(double& it) {
  it += 10.0;
  std::cout << "Within function, it = " << it << std::endl;
  return it;
}

int main(void) {
  double it = 5.0;
  std::cout << "Before function execution, it = " << it << std::endl;

  std::cout << "Call-by-value" << std::endl;
  std::cout << "Before function execution, it = " << it << std::endl;
  double result = ChangeItByValue(it);
  std::cout << "After function execution, it = " << it
            << "\nResult returned is " << result << std::endl;

  std::cout << "Call-by-pointer" << std::endl;
  std::cout << "Before function execution, it = " << it << std::endl;
  result = ChangeItByPointer(&it);
  std::cout << "After function execution, it = " << it
            << "\nResult returned is " << result << std::endl;

  std::cout << "Call-by-reference" << std::endl;
  std::cout << "Before function execution, it = " << it << std::endl;
  result = ChangeItByReference(it);
  std::cout << "After function execution, it = " << it
            << "\nResult returned is " << result << std::endl;

  return 0;
}