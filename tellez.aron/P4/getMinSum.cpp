#include "getMinSum.hpp"
#include <stdexcept>

size_t calculateSum(const size_t *arr, size_t n, size_t i, size_t j)
{
  if (i <= j)
  {
    return arr[i * n + j] + ((i + j < n - 1) ? arr[i * n + n - 1 - j] : 0);
  }
  else
  {
    return arr[j * n + i] + ((i + j < n - 1) ? arr[j * n + n - 1 - i] : 0);
  }
}

size_t getMinSum(const size_t *arr, size_t m, size_t n)
{
  if (m == 0 || n == 0)
    return 0;
  if (m != n)
    throw std::invalid_argument("La matriz debe ser cuadrada");
  size_t minSum = arr[0];
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      size_t sum = calculateSum(arr, n, i, j);
      if (sum < minSum)
        minSum = sum;
    }
  }
  return minSum;
}
