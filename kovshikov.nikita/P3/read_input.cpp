#include "read_input.hpp"

size_t kovshikov::readInput(char * array)
{
  size_t size = 25;
  size_t read = 0;
  char symbol = 0;
  int add = 25;
  char * newArray = nullptr;
  while ((std::cin >> symbol) && (symbol != '\n'))
  {
    if (read == size)
    {
      newArray = new char[size + add];
      for(size_t i = 0; i < size; i++)
      {
        newArray[i] = array[i];
      }
      delete[] array;
      array = newArray;
      newArray = nullptr;
      size += add;
    }
    array[read++] = symbol;
  }
  return read;
}
