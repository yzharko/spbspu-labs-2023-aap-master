#include "incremArr.hpp"

char * ponomarev::incremArr(char * line, size_t incremOfEl, size_t numOfEl)
{
  char * enlargedArr = new char[numOfEl + incremOfEl] {};
  for (size_t i = 0; i < numOfEl; i++)
  {
    enlargedArr[i] = line[i];
  }
  return enlargedArr;
}
