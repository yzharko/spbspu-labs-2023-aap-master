#include <iostream>
#include <cstddef>
#include "functions.hpp"

size_t zheleznyakov::readLine(char * input)
{
  char c = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    input[read++] = c;
    if (c == '\n')
    {
      input[read - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  return read;
}

size_t zheleznyakov::findNonDuplicateChars(char * dest, char * str1, char * str2, size_t size1, size_t size2)
{
  size_t charSize = 0;
  for (size_t i = 0; i < size2; i++)
  {
    if (std::strchr(str1, str2[i]) == NULL)
    {
        dest[charSize++] = str2[i];
    }
  }
  for (size_t i = 0; i < size1; i++)
  {
    if (std::strchr(str2, str1[i]) == NULL)
    {
        dest[charSize++] = str1[i];
    }
  }
  return charSize;
}
