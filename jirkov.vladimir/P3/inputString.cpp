#include "inputString.hpp"
#include <iostream>
#include <cstring>

char* increaseNewScope(const char* string, size_t newSize, size_t& newScope)
{
  newScope = newSize * 2;
  char* newString = new char[newScope];
  std::memcpy(newString, string, newSize);
  return newString;
}

char* inputString(std::istream& input)
{
  size_t scope = 10;
  size_t size = 0;
  char* string = new char[scope];
  string[0] = '\0';
  std::cin >> std::noskipws;
  do
  {
    if (size == scope)
    {
      char* newstring = increaseNewScope(string, size, scope);
      if (newstring == nullptr)
      {
        std::cerr << "Dynamic memory reading error\n";
        delete[] string;
        return nullptr;
      }
      delete[] string;
      string = newstring;
      newstring = nullptr;
    }
     std::cin >> string[size];
  }
  while (input && string[size++] != '\n');
  if (string[0] == '\0' || string[0] == '\n')
  {
    std::cerr << "Input error\n";
    delete[] string;
    return nullptr;
  }
  return string;
}
