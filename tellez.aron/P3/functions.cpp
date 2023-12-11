#include "functions.hpp"
#include <cstring>
#include <cctype>
#include <algorithm>

char* remplaceChar(const char* str, size_t size, char replaceFrom, char replaceTo)
{
  char* result = new char[size + 1];
  for (size_t i = 0; i < size; ++i)
  {
    result[i] = (str[i] == replaceFrom) ? replaceTo : str[i];
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
