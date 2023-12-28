#include <iostream>
#include <cstring>
#include "inputString.hpp"
char* inputString(std::istream& input, size_t& size, size_t& scope)
{
  char* string = new char[scope];
  size = 0;
  string[0] = '\0';
  input >> std::noskipws;
  do
  {
    if (size == scope)
    {
      size_t newScope = scope * 2;
      char* newString = new char[newScope];
      for (size_t i = 0; i < scope; i++)
      {
        newString[i] = string[i];
      }
      delete[] string;
      string = newString;
      scope = newScope;
    }
    std::cin >> string[size];
  } while (input && string[size++] != '\n');
  if (string[0] == '\0' || string[0] == '\n')
  {
    std::cerr << "Input error\n";
    delete[] string;
    return nullptr;
  }
  return string;
}
