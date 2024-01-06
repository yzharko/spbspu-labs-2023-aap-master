#include <cctype>
#include "functions.hpp"

size_t zheleznyakov::removeLetters(char *dest, char *str, size_t size)
{
  size_t resSize = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (!isalpha(*str))
    {
      *(dest++) = *(str++);
      ++resSize;
    }
    else
    {
      ++str;
    }
  }
  return resSize;
}
