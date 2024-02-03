#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace miheev
{
  size_t inputToArr(std::ifstream& in, int* arr, size_t size);
  void printArrInline(const int* const arr, size_t size);
  bool isUInt(char* str);
}

#endif
