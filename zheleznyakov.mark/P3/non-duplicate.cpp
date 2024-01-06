#include <iostream>
#include "functions.hpp"

bool zheleznyakov::findSymbol(const char * str, int c) {
    const size_t len = str[0];
    for (size_t i = 0; i < len; ++i) {
        if (str[i] == static_cast<char>(c)) {
            return true;
        }
    }
    return false;
}

size_t zheleznyakov::findNonDuplicateChars(char * dest, char * str1, const char * str2, size_t size1, size_t size2)
{
  size_t charSize = 0;
  for (size_t i = 0; i < size2; i++)
  {
    if (!(zheleznyakov::findSymbol(str1, str2[i])))
    {
        dest[charSize++] = str2[i];
    }
  }
  for (size_t i = 0; i < size1; i++)
  {
    if (!(zheleznyakov::findSymbol(str2, str1[i])))
    {
        dest[charSize++] = str1[i];
    }
  }
  return charSize;
}
