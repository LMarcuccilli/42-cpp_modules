
#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
  Array<int> a(3);

  for (unsigned int i = 0; i < a.size(); i++)
    a[i] = i + 1;

  std::cout << "Array a: ";
  for (unsigned int i = 0; i < a.size(); i++)
    std::cout << a[i] << " ";
  std::cout << std::endl;

  Array<int> b(a);
  b[0] = 42;

  std::cout << "a[0] = " << a[0] << std::endl;
  std::cout << "b[0] = " << b[0] << std::endl;

  Array<int> c;
  c = a;
  c[1] = 99;

  std::cout << "a[1] = " << a[1] << std::endl;
  std::cout << "c[1] = " << c[1] << std::endl;

  Array<std::string> words(2);
  words[0] = "hello";
  words[1] = "world";

  std::cout << words[0] << " " << words[1] << std::endl;

  try {
    std::cout << a[10] << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Exception caught" << std::endl;
  }

  return 0;
}
