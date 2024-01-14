#include "findingLocMax.hpp"

size_t doroshenko::findingLocMax(const int* Matrix, size_t rows_, size_t cols_)
{
  size_t cntLocMax = 0;
  for (size_t i = 1; i < rows_ - 1; i++)
  {
    for (size_t j = 1; j < cols_ - 1; j++)
    {
      bool firstCond = (Matrix[i * j] < Matrix[(i - 1) * j]) ? 1 : 0;
      bool secondCond = (Matrix[i * j] < Matrix[i * (j - 1)]) ? 1 : 0;
      bool thirdCond = (Matrix[i * j] < Matrix[(i + 1) * j]) ? 1 : 0;
      bool fourthCond = (Matrix[i * j] < Matrix[i * (j + 1)]) ? 1 : 0;
      if (firstCond == 1 && secondCond == 1 && thirdCond == 1 && fourthCond == 1)
      {
        cntLocMax++;
      }
    }
  }
  return cntLocMax;
}
