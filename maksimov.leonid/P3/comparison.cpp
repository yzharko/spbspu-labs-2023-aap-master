#include "comparison.hpp"

size_t comparison(const char* str, const size_t lenStr, const char* etalonStr)
{
  size_t count = 0;
  for (size_t i = 0; i < lenStr; i++)
  {
    for (size_t j = 0; j < size_t(sizeof(etalonStr) - 1); j++)
    {
      if (int(str[i]) == int(etalonStr[j]) && int(str[i]) != 10 && int(str[i]) != 0)
      {
        count++;
        break;
      }
    }
  }
  return count;
}
