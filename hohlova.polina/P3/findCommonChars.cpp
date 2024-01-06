#include "findCommonChars.hpp"

int hohlova::findCommonChars(const char* s, size_t size)
{
  for (size_t i = 0; i < size - 1; i++)
  {
    if (s[i] == s[i + 1])
    {
      return 1;
    }
  }
  return 0;
}

