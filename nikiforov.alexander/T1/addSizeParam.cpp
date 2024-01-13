#include "addSizeParam.hpp"
#include <string>

void nikiforov::AddFourElem(double*& arr, size_t& countElem)
{
  double* ArrElem = new double[countElem] {};
  for (size_t i = 0; i < countElem; i++)
  {
    ArrElem[i] = arr[i];
  }
  delete[] arr;
  arr = ArrElem;
}

void nikiforov::AddThreeElem(double*& arr, size_t& countElem)
{
  double* ArrElem = new double[countElem];
  for (size_t i = 0; i < countElem; i++)
  {
    ArrElem[i] = arr[i];
  }
  delete[] arr;
  arr = ArrElem;
}
