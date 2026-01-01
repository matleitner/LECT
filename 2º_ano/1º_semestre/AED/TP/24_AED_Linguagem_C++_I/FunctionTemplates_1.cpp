//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// J. Madeira --- February 2022
//

#include <iostream>
#include <string>

// Avoid duplication of code (see overloading example)

template <typename T>
T plus(T a, T b) {
  return a + b;
}

int main(void) {
  int n = plus(3, 4);
  std::cout << "plus(3, 4) returns " << n << std::endl;

  double d = plus(3.2, 4.2);
  std::cout << "plus(3.2, 4.2) returns " << d << std::endl;

  std::string s1 = "aaa";
  std::string s2 = "bbb";
  std::string s3 = plus(s1, s2);
  std::string s4 = plus(s2, s1);
  std::cout << "With s1 as " << s1 << " and s2 as " << s2 << std::endl;
  std::cout << "plus(s1, s2) returns " << s3 << std::endl;
  std::cout << "plus(s2, s1) returns " << s4 << std::endl;

  return 0;
}