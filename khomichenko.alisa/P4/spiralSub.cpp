#include "spiralSub.hpp"
#include <iostream>

void khomichenko::spiSub(size_t start, size_t inc, size_t rows, int * matrix)
{
  if (rows == 1)
  {
    matrix[start] += inc;
    --inc;
    return;
  }
  size_t stop = start;
  for (size_t i = start; i != rows; ++i)
  {
    matrix[i] += inc;
    --inc;
    stop = i;
  }
  for(size_t i = stop+rows; i != stop+rows*(rows); i = i + rows)
  {
    matrix[i] += inc;
    --inc;
    start = i;
  }
  for(size_t i = start-1; i != start - (rows); --i)
  {
    matrix[i] += inc;
    --inc;
    stop = i;
  }
  for(size_t i = stop-rows; i > stop - rows * (rows - 1); i = i - rows)
  {
    matrix[i] += inc;
    --inc;
    stop = i;
  }
}

void khomichenko::callFuncSec(int* matrix, size_t cols, size_t rows)
{
  size_t start = 0;
  size_t inc = -1;
  size_t j = 0;
  while (j + 1 != cols)
  {
    ++j;
    spiSub(start, inc, rows, matrix);
    start = start + cols + 1;
    inc -= (2*rows+2*(rows-2));
    rows -= 2;
  }
}
