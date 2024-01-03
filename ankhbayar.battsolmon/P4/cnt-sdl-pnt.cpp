#include "cnt-sdl-pnt.hpp"

tsomo::Saddle::Saddle() :
  count(0),
  minrows(std::numeric_limits< size_t >::max()),
  maxcols(std::numeric_limits< size_t >::min()),
  coordinateMinRowsj(0)
{};
size_t tsomo::Saddle::operator()(size_t rows, size_t cols, size_t* matrix)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (matrix[i * cols + j] <= minrows)
      {
        minrows = matrix[i * cols + j];
        coordinateMinRowsj = j;
      }
    }
    for (size_t q = 0; q < rows; ++q)
    {
      if (matrix[q * cols + coordinateMinRowsj] >= maxcols)
      {
        maxcols = matrix[i * cols + coordinateMinRowsj];
      }
    }
    if (minrows == maxcols)
    {
      count += 1;
    }
  }
  return count;
}
