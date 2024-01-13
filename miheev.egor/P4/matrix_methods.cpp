#include "matrix_methods.hpp"

void miheev::increaseRectBorder(int* arr, size_t cols, size_t xStart, size_t yStart, size_t width, size_t height, int increment)
{
  if (height == 1)
  {
    arr[cols * yStart + xStart] += increment;
  }
  else
  {
    for (size_t j = xStart; j < xStart + width; j++)
    {
      arr[cols * yStart + j] += increment;
      arr[cols*(yStart + height - 1) + j] += increment;
    }
    for (size_t i = yStart + 1; i < yStart + height - 1; i++)
    {
      arr[i * cols + xStart] += increment;
      arr[i * cols + xStart + width - 1] += increment;
    }
  }
}

void miheev::increasePeriphery(int* arr, size_t rows, size_t cols)
{
  int increment = 1;
  size_t xs = 0;
  size_t ys = 0;
  size_t w = cols;
  size_t h = rows;
  while (ys + h <= rows && xs + w <= cols && h > 0 && w > 0)
  {
    miheev::increaseRectBorder(arr, cols, xs, ys, w, h, increment);
    xs += 1;
    ys += 1;
    w = w > 2 ? w - 2 : 0;
    h = h > 2 ? h - 2 : 0;
    increment += 1;
  }
}
