#include "fillArray.hpp"
size_t seryj::fillArray(size_t max_size, size_t to_read, std::ifstream & input, int * values)
{
  for (size_t i = 0; i < std::min(to_read, max_size); ++i)
  {
    if (!(input >> *(values + i)))
      return i;
  }
  return std::min(to_read, max_size);
}
