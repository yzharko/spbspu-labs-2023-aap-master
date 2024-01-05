#include <iostream>
#include <cstring>
#include "inputString.hpp"
#include "checkDuplicatesChars.hpp"

int main(){
  size_t scope = 10;
  size_t size = 0;
  char* string = inputString(std::cin, size, scope);
  if (string == nullptr)
  {
    std::cerr << "String reading error\n";
    return 1;
  }
  int Result = checkDuplicatesChars(string, size);
  std::cout << Result << '\n';
  delete[] string;
  return 0;
}
