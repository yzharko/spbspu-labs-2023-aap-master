#include "delvow.hpp"

char* delVow(const char* str, const size_t lenStr)
{
  const char* vowels = "eyuioaEYUIOA";
  char* newStr = new char[lenStr]{};
  for (size_t i = 0; i < lenStr; i++)
  {
    newStr[i] = str[i];
    for (size_t j = 0; j < size_t(sizeof(vowels) - 2); j++)
    {
      if (int(str[i]) == int(vowels[j]))
      {
        newStr[i] = '\0';
      }
    }
  }
  delete[] str;
  return newStr;
}
