#include "functions.hpp"

char* doroshenko::resizeArray(char* array, size_t size, size_t newSize)
{
  char* newArray = new char[newSize];
  size_t i;
  size_t j;
  for (i = 0; i < size; i++)
  {
    newArray[i] = array[i];
  }
  for (j = size; j < newSize; j++)
  {
    newArray[j] = '0';
  }
  delete[] array;
  return newArray;
}

char* doroshenko::readInput(char* input, std::istream& in, size_t& readEl)
{
  char ch = 0;
  size_t size = 20;
  input = new char[20];
  while (in >> ch)
  {
    if (readEl < size)
    {
      input[readEl++] = ch;
      if (ch == '\n')
      {
        input[readEl - 1] = '\0';
        break;
      }
    }
    else
    {
      input = doroshenko::resizeArray(input, size, size + 20);
      size += 20;
      input[readEl++] = ch;
    }
  }
  return input;
}

void doroshenko::removeDup(char* input, size_t readEl)
{
  int pair = 0;
  for (size_t i = 0; i < readEl - 1; i++)
  {
    for (size_t j = i + 1; j < readEl; j++)
    {
      if (input[i] == input[j])
      {
        pair = 1;
        input[j] = '\0';
      }
    }
    if (pair == 1)
    {
      std::cout << input[i];
      input[i] = '\0';
      pair = 0;
    }
    pair = 0;
  }
}
