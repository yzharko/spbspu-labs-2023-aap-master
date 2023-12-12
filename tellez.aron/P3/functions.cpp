#include "functions.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>

char* remplaceChar(const char* str, size_t size, char replaceFrom, char replaceTo)
{
  if (str == nullptr)
  {
    std::cerr << "Error: Input string is null\n";
    return nullptr;
  }
  char* result = new char[size + 1]();
  for (size_t i = 0; i < size; ++i)
  {
    result[i] = (str[i] == replaceFrom && str[i] != '\0') ? replaceTo : str[i];
  }
  result[size] = '\0';
  return result;
}

int hasRepeatedChars(const char* str, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (std::count(str, str + size, str[i]) > 1)
    {
      return 1;
    }
  }
  return 0;
}
