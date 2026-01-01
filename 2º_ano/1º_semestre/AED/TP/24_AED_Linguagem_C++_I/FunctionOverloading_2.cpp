//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// J. Madeira --- February 2022
//
// Adapted from the I. Horton examples
//

#include <iostream>
#include <string>

// returns 0 if the arguments are equal,
// -1 if arg1 is smaller,
// 1 if arg2 is // smaller

int compare(const int &v1, const int &v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

int compare(const double &v1, const double &v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

int compare(const char &v1, const char &v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

int compare(const std::string &v1, const std::string &v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

int main(void) {
  int m = 10;
  int n = 100;
  std::cout << "With m as " << m << " and n as " << n << std::endl;
  std::cout << "compare(m, n) returns " << compare(m, n) << std::endl;
  std::cout << "compare(n, m) returns " << compare(n, m) << std::endl;

  double x = 10.5;
  double y = 10.25;
  std::cout << "With x as " << x << " and y as " << y << std::endl;
  std::cout << "compare(x, y) returns " << compare(x, y) << std::endl;
  std::cout << "compare(y, x) returns " << compare(y, x) << std::endl;

  char c1 = 'a';
  char c2 = 'A';
  std::cout << "With c1 as " << c1 << " and c2 as " << c2 << std::endl;
  std::cout << "compare(c1, c2) returns " << compare(c1, c2) << std::endl;
  std::cout << "compare(c2, c1) returns " << compare(c2, c1) << std::endl;

  std::string s1 = "aaa";
  std::string s2 = "bbb";
  std::cout << "With s1 as " << s1 << " and s2 as " << s2 << std::endl;
  std::cout << "compare(s1, s2) returns " << compare(s1, s2) << std::endl;
  std::cout << "compare(s2, s1) returns " << compare(s2, s1) << std::endl;

  return 0;
}