#include "incPer.hpp"
#include <iostream>

void khomichenko::doInc(size_t start, size_t inc, size_t rows, int * matrix)
{
  if (rows == 1)
  {
    matrix[start] += inc;
    return;
  }
  int stop = start;
  for (size_t i = start; i != rows; ++i)
  {
    matrix[i] += inc;
    stop = i;
  }
  for(size_t i = stop+rows; i != stop+rows*(rows); i = i + rows)
  {
    matrix[i] += inc;
    start = i;
  }
  for(size_t i = start-1; i != start - (rows); --i)
  {
    matrix[i] += inc;
    stop = i;
  }
  for(size_t i = stop-rows; i > stop - rows * (rows - 1); i = i - rows)
  {
    matrix[i] += inc;
    stop = i;
  }
}

void khomichenko::callFunc(int* matrix, const size_t cols, size_t rows)
{
  size_t start = 0;
  size_t inc = 1;
  size_t j = 0;
  while (j + 1 != cols)
  {
    ++j;
    doInc(start, inc, rows, matrix);
    start = start + cols + 1;
    inc += 1;
    rows -= 2;
  }
}
