#include "functions.hpp"
#include <iostream>
#include <cctype>

size_t miheev::inputToArr(std::ifstream& in, int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    in >> arr[i];
    if (!in)
    {
      std::cerr << "something went wrong only " << i << " elements were initialized\n";
      return i;
    }
  }
  return size;
}

void miheev::printArrInline(const int* const arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

bool miheev::isUInt(char* str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (!std::isdigit(str[i]))
    {
      return 0;
    }
  }
  return 1;
}
