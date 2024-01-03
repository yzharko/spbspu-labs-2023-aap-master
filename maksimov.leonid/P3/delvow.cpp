#include "delvow.hpp"

void arr::delVow(char*& str, size_t lenStr)
{
  const char* vowels = "eyuioaEYUIOA";
  for (size_t i = 0; i < lenStr; i++)
  {
    for (size_t j = 0; j < size_t(sizeof(vowels) - 2); j++)
    {
      if (int(str[i]) == int(vowels[j]))
      {
        str[i] = char(0);
      }
    }
  }
}
