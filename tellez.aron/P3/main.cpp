#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>
#include "functions.hpp"
int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      char* newString = new char[capacity + 10];
      std::memcpy(newString, cstring, size);
      delete[] cstring;
      cstring = newString;
      capacity += 20;
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cerr << "Error while reading the string \n";
    delete[] cstring;
    return 1;
  }
  char replaceFrom, replaceTo;
  std::cout << "Enter the first character to replace: ";
  std::cin >> replaceFrom;
  std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
  std::cout << "Enter the second character for replacement: ";
  std::cin >> replaceTo;
  char* replacedResult = remplaceChar(cstring, size, replaceFrom, replaceTo);
  size_t hasRepResult = hasRepeatedChars(cstring, size);
  std::cout << "new string: " <<replacedResult << "there are duplicate characters: " << hasRepResult << "\n";
  delete[] replacedResult;
  delete[] cstring;
  return 0;
}
