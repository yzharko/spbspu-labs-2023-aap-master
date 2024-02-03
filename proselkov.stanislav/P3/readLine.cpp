#include "readLine.hpp"
#include <iostream>
#include <cstddef>

size_t readLine(char * input)
{
  char symbol = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> symbol) && (symbol != '\n'))
  {
    if (read == 10)
    {
      newArray = new char[size + 10];
      for(size_t i = 0; i < size; i++)
      {
        newArray[i] = array[i];
      }
      delete[] array;
      array = newArray;
      newArray = nullptr;
      size += 10;
    }
    array[read++] = symbol;
  }
  std::cin >> std::skipws;
  return read;
}
