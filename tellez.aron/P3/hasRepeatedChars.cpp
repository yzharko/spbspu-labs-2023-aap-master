#include "hasRepeatedChars.hpp"
#include <cstddef>
#include <algorithm>

size_t hasRepeatedChars(const char* str, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (std::count(str, str + size, str[i]) > 1)
    {
      return 1;
    }
  }
  return 0;
}
