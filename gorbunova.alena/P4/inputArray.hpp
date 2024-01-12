#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP
#include <iosfwd>

namespace gorbunova
{
  int readFixedSizeArray(const char* fileName, int(&fixedArray)[100][100], int& rows, int& cols);
  int readDynamicSizeArray(const char* fileName, int**& dynamicArray, int& rows, int& cols);
  int writeResultToFile(const char* fileName, int result);
}
#endif
