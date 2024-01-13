#include "addSizeParam.hpp"
#include <string>

void nikiforov::AddFourElem(double*& arr, size_t& countElem)
{
  double* ArrElem = new double[countElem + 4];
  for (size_t i = 0; i < countElem; i++)
  {
    ArrElem[i] = arr[i];
  }
  delete[] arr;
  countElem += 4;
  arr = ArrElem;
}

void nikiforov::AddThreeElem(double*& arr, size_t& countElem)
{
  double* ArrElem = new double[countElem + 3];
  for (size_t i = 0; i < countElem; i++)
  {
    ArrElem[i] = arr[i];
  }
  delete[] arr;
  countElem += 3;
  arr = ArrElem;
}
