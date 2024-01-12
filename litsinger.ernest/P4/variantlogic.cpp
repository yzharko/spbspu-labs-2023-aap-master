#include "variantlogic.hpp"
namespace litsinger
{
  int MaximalSum(const int * arr, size_t rows, size_t cols)
  {
    int maxSum = arr[0];
    for (size_t i = 1; i < rows; ++i)
    {
      int sum = 0;
      for (size_t j = 0; j <= i; ++j)
      {
        sum += arr[i * cols + j] + arr[j * cols + i];
      }
      if (sum > maxSum)
      {
        maxSum = sum;
      }
    }
    for (size_t j = 1; j < cols; ++j)
    {
      int sum = 0;
      for (size_t i = 0; i < rows && i + j < cols; ++i)
      {
        sum += arr[i * cols + i + j] + arr[(i + j) * cols + i];
      }
      if (sum > maxSum)
      {
        maxSum = sum;
      }
    }
    return maxSum;
  }
}
