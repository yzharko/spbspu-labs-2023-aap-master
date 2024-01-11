#include "remplaceChar.hpp"
#include <algorithm>

char* remplaceChar(const char* str, size_t size, char replaceFrom, char replaceTo)
{
  char* result = new char[size + 1]();
  for (size_t i = 0; i < size; ++i)
  {
    if (str[i] == replaceFrom && str[i] != '\0')
    {
      result[i] = replaceTo;
    }
    else
    {
      result[i] = str[i];
    }
  }
  result[size] = '\0';
  return result;
}
