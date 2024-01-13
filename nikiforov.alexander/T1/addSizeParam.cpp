#include "addSizeParam.hpp"
#include <string>

double* nikiforov::AddFourElem(double*& arr, size_t& countElem)
{
  double* ArrElem = new double[countElem += 4];
  for (size_t i = 0; i < countElem; i++)
  {
    ArrElem[i] = arr[i];
  }
  delete[] arr;
  return ArrElem;
}

double* nikiforov::AddThreeElem(double*& arr, size_t& countElem)
{
  double* ArrElem = new double[countElem += 3];
  for (size_t i = 0; i < countElem; i++)
  {
    ArrElem[i] = arr[i];
  }
  delete[] arr;
  return ArrElem;
}
