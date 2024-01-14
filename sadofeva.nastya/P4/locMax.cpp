#include "locMax.hpp"

size_t sadofeva::locMax(int * values, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < rows;i++)
  {
    for (size_t j = 0; j < cols;j++)
    {
      if (*(values + (i * j)) > *(values + (i * j + 1)) && *(values + (i * j -1)) < *(values + (i * j)))
      {
        count++;
      }
    }
  }
  return count;
}
