#include "AddElem.hpp"

void nikiforov::AddElem(char*& arr, size_t& size, size_t& lenth)
{
  if (lenth == size)
  {
    char* newArr = new char[lenth + 10];

    for (size_t i = 0; i < lenth; i++)
    {
      newArr[i] = arr[i];
    }
    size += 10;
    delete[] arr;
    arr = newArr;
  }
}
