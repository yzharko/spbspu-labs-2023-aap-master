#include "delzero.hpp"

char* delzero(char* arr, size_t& sizeArr)
{
  size_t count = 0;
  for (size_t i = 0; i < sizeArr; i++)
  {
    if (int(arr[i]) <= 0)
    {
      count++;
    }
  }
  char* newArr = new char[(sizeArr - count) + 1]{};
  size_t counter = 0;
  for (size_t i = 0; i < sizeArr; i++)
  {
    if (int(arr[i]) > 0)
    {
      newArr[counter++] = arr[i];
    }
  }
  newArr[sizeArr - count] = '\0';
  delete[] arr;
  arr = newArr;
  sizeArr = (sizeArr - count) + 1;
  return newArr;
}
