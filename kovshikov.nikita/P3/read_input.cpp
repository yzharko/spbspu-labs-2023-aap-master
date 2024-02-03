#include "read_input.hpp"

char * kovshikov::readInput(size_t &size, size_t &read)
{
  char symbol = 0;
  int add = 25;
  char * array = new char[size];
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
  return array;
}
