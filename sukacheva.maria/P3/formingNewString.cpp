#include "formingNewString.hpp"
#include <iostream>

char* sukacheva::formingNewString(char* first, const char* second, size_t firstStringSize, const size_t secondStringSize)
{
  size_t count = 0;
  for (size_t i = 0; i < secondStringSize; ++i)
  {
    if (std::isdigit(second[i]))
    {
      count += 1;
    }
  }
  char* result = new char[firstStringSize + 1 + count] {};
  for (size_t i = 0; i < firstStringSize; i++)
  {
    result[i] = first[i];
  }
  size_t size = firstStringSize;
  for (size_t j = 0; j < secondStringSize; j++)
  {
    if (std::isdigit(second[j]))
    {
      result[size] = second[j];
      size += 1;
    }
  }
  return result;
}
