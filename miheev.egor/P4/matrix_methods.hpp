#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include <cstddef>
#include <fstream>

namespace miheev
{
  void increaseRectBorder(int* arr, size_t cols,
    size_t xStart, size_t yStart, size_t width, size_t height, int increment);
  void increasePeriphery(int* arr, size_t rows, size_t cols);
}
#endif
