#include <iostream>
#include "inputArray.hpp"
#include "matrixCheck.hpp"

int main(int argc, char** argv)
{
  using namespace gorbunova;

  if (argc < 4)
  {
     std::cerr << "Not enough arguments\n";
     return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  char* end = nullptr;
  long long num = std::strtoll(argv[1], std::addressof(end), 10);
  if (*end != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 3;
  }
  if (num < 1 || num > 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  const char* input = argv[2];
  const char* output = argv[3];
  int rows = 0, cols = 0;
  int flag;
  if (num == 1)
  {
    int staticArray[100][100];
    flag = readFixedSizeArray(input, staticArray, rows, cols);
    if (flag == 2)
    {
      return 2;
    }
    int isUpperTriangularResult = isUpperTriangular(staticArray, rows, cols);
    if (isUpperTriangularResult == 2)
    {
      return 2;
    }
    flag = writeResultToFile(output, isUpperTriangularResult);
    if (flag == 2)
    {
        return 2;
    }
  }
  else if (num == 2)
  {
    int** dynamicArray = nullptr;
    flag = readDynamicSizeArray(input, dynamicArray, rows, cols);
    if (flag == 2)
    {
      return 2;
    }
    int isUpperTriangularResult = isUpperTriangular(dynamicArray, rows, cols);
    if (isUpperTriangularResult == 2)
    {
      return 2;
    }
    flag = writeResultToFile(output, isUpperTriangularResult);
    if (flag == 2)
    {
      return 2;
    }
    for (int i = 0; i < rows; ++i)
    {
      delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
  }
  return 0;
}
