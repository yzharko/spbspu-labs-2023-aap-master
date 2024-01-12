#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>
#include "remplaceChar.hpp"
#include "hasRepeatedChars.hpp"
#include "readDynamicString.hpp"

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  char* cstring = readDynamicString(size, capacity);
  if (cstring == nullptr)
  {
    return 1;
  }
  char replaceFrom = '\0', replaceTo = '\0';
  std::cout << "Enter the first character to replace: ";
  std::cin >> replaceFrom;
  std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
  std::cout << "Enter the second character for replacement: ";
  std::cin >> replaceTo;
  char* replacedResult = remplaceChar(cstring, size, replaceFrom, replaceTo);
  size_t hasRepResult = hasRepeatedChars(cstring, size);
  std::cout << "New string: " << replacedResult << "There are duplicate characters: " << hasRepResult << "\n";
  delete[] replacedResult;
  delete[] cstring;
  return 0;
}
