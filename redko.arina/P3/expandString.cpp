#include "expandString.hpp"

char * redko::expandString(char * src, int len)
{
  int add = 10;
  char * expandedStr = new char[len + add];
  if (!expandedStr)
  {
    return nullptr;
  }
  for (int i = 0; i < len; i++)
  {
    expandedStr[i] = src[i];
  }
  delete[] src;
  return expandedStr;
}
