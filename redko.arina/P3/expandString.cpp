#include "expandString.hpp"
#include <new>

char * redko::expandString(char * src, int len, int add)
{
  char * expandedStr = new (std::nothrow) char[len + add];
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
