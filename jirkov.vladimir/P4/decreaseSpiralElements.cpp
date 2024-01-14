#include "decreaseSpiralElements.hpp"
#include <iosfwd>

void jirkov::fillTopRow(int* matrix, int rowend, int cols, int& num)
{
  for (int c = rowend; c >= 0; c--)
  {
    matrix[rowend * cols + c] = num;
    num--;
  }
}

void jirkov::fillRightColumn(int* matrix, int colend, int rows, int cols, int& num)
{
  for (int r = rows - 1; r >= 0; r--)
  {
    matrix[r * cols + colend] = num;
    num--;
  }
}

void jirkov::fillBottomRow(int* matrix, int rowstart, int colstart, int cols, int& num)
{
  for (int c = cols - 1; c >= colstart; c--)
  {
    matrix[rowstart * cols + c] = num;
    num--;
  }
}

void jirkov::fillLeftColumn(int* matrix, int colstart, int rowstart, int cols, int rows, int& num)
{
  for (int r = rows - 1; r > rowstart; r--)
  {
    matrix[r * cols + colstart] = num;
    num--;
  }
}

void jirkov::decreaseSpiralElements(int* matrix, int rows, int cols)
{
  int num = -1;
  int rowstart = 0;
  int rowend = rows - 1;
  int colstart = 0;
  int colend = cols - 1;
  while (rowstart <= rowend && colstart <= colend)
  {
    fillTopRow(matrix, rowend, cols, num);
    fillRightColumn(matrix, colend, rows, cols, num);
    fillBottomRow(matrix, rowstart, colstart, cols, num);
    fillLeftColumn(matrix, colstart, rowstart, rows, cols, num);
    rowstart++;
    rowend--;
    colstart++;
    colend--;
  }
}
