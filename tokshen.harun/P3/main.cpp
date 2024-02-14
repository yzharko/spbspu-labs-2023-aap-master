#include <iostream>
#include "upplow.hpp"
#include "lat_two.hpp"

int main() {

  size_t length = 20;
  char* str1 = new char[length + 1];
  char* str2 = new char[length + 1];
  std::cout << "Enter 1st string: " << "\n";
  std::cin.getline(str1, length + 1);

  size_t inputLength = strlen(str1);

  char* temp = new char[inputLength + 1];

  toksen::convertToLower(str1, temp, inputLength);

  std::cout << temp << std::endl;

  std::cout << "Enter second string : " << "\n";
  std::cin.getline(str2, length + 1);
  char* mergeString = toksen::mergeLatinLetters(temp, str2);
  std::cout << mergeString;

  delete[] str1;
  delete[] str2;
  delete[] temp;

  return 0;
}
