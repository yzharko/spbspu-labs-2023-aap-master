#include <iostream>
#include "addarr.hpp"

void addarr(std::istream& in, char*& arr, size_t& size_arr, bool& endin)
{
  char* newArr = new char[(size_arr * 2) + 1]{};
  for (size_t i = 0; i < size_arr; i++)
  {
    newArr[i] = arr[i];
  }
  size_t count = size_arr;
  char temp = 0;
  while ((in >> temp) && count < (size_arr * 2) - 1)
  {
    if (temp == '\n')
    {
      endin = 0;
      break;
    }
    newArr[count++] = temp;
  }
  if (temp == 0)
  {
    delete[] arr;
    delete[] newArr;
    throw std::exception();
  }
  newArr[count] = temp;
  delete[] arr;
  arr = newArr;
  size_arr *= 2;
}
