#include <iostream>
#include <cstring>
#include <cctype>
#include "newCapacityCstring.hpp"
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
      char* newCString = makeNewCapacityCString(cstring, capacity, size);
      if (newCString == nullptr)
      {
        std::cerr << "Error: Unable to allocate memory for new capacity\n";
        delete[] cstring;
        return 1;
      }
      delete[] cstring;
      cstring = newCString;
      newCString = nullptr;
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
  char* replacedResult = remplaceChar(cstring, replaceFrom, replaceTo);
  size_t hasRepResult = hasRepeatedChars(cstring);
  std::cout << "New string: " <<replacedResult << "There are duplicate characters: " << hasRepResult << "\n";
  delete[] replacedResult;
  delete[] cstring;
  return 0;
}
