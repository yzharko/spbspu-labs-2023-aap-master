#include "findMaxColumn.hpp"

int shagieva::findMaxColumn(const int * values, const int numberOfRows, const int numberOfColumns)
{
  int maxColumn = 0;
  int maxSeq = 0;
  int maxCurrentSeq = 0;

  for (int column = 0; column < numberOfColumns; column++)
  {
    int currentSeq = 0;

    for (int row = 1; row < numberOfRows; row++)
    {
      int currentNumber = values[row * numberOfColumns + column];
      int previousNumber = values[(row - 1) * numberOfColumns + column];

      if (currentNumber == previousNumber)
      {
        currentSeq++;
      }

      else if (currentSeq > maxCurrentSeq)
      {
        maxCurrentSeq = currentSeq;
      }
    }

    if (maxCurrentSeq > maxSeq)
    {
      maxSeq = maxCurrentSeq;
      maxColumn = column + 1;
    }
  }
  return maxColumn;
}
