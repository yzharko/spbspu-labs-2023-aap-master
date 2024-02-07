#include "addSizeLine.hpp"

char* nikiforov::AddElem(char* arr, size_t size, size_t read)
{
  char* newArr = new char[read + size];

  for (size_t i = 0; i < read; i++)
  {
    newArr[i] = arr[i];
  }
  delete[] arr;
  return newArr;
}
