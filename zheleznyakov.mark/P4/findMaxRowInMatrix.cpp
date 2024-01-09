#include "functions.hpp"

int zheleznyakov::findMaxRowInMatrix(const int * matrix, int columns, int rows)
{
  int maxColumn = 0;
  int maxSequenceLength = 0;
  for (int col = 0; col < columns; col++)
  {
    int currentStreak = 0;
    int maxCurrentStreak = 0;
    for (int row = 1; row < rows; row++)
    {
      const int current = matrix[row * columns + col];
      const int previous = matrix[(row - 1) * columns + col];
      if (current == previous)
      {
        currentStreak++;
      }
      if (maxCurrentStreak < currentStreak)
      {
        maxCurrentStreak = currentStreak;
      }
    }
    if (maxSequenceLength < maxCurrentStreak)
    {
      maxSequenceLength = maxCurrentStreak;
      maxColumn = col + 1;
    }
  }
  return maxColumn;
}
