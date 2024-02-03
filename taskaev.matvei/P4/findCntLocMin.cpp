#include "findCntLocMin.hpp"
#include <iostream>

int taskaev::funcLineMin(int firstN, int secondN, int threeN)
{
  return ((((firstN < secondN) ? firstN : secondN) < threeN) ? ((firstN < secondN) ? firstN : secondN) : threeN);
}
int taskaev::locMin(int firstN, int secondN, int threeN, int fourN)
{
  return ((funcLineMin(firstN, secondN, threeN) < fourN) ? (funcLineMin(firstN, secondN, threeN)) : fourN);
}
int taskaev::findCntLocMin(int matrix[], int rows, int cols)
{
  if ((rows <= 2) || (cols <= 2))
  {
    std::cout << "Error no CntLocMin.\n";
    return 1;
  }
  int CntLocMin = 0;
  for (int i = cols + 1; i < ((rows - 1) * cols); i++)
  {
    if ((i % cols != 0) && ((i + 1) % cols != 0))
    {
      int lineUpMin = funcLineMin(matrix[i - cols - 1], matrix[i - cols], matrix[i - cols + 1]);
      int lineDownMin = funcLineMin(matrix[i + cols - 1], matrix[i + cols], matrix[i + cols + 1]);
      if (matrix[i] < locMin(lineUpMin,lineDownMin,matrix[i - 1], matrix[i +  1]))
      {
        CntLocMin = CntLocMin + 1;
      }
    }
  }
  return CntLocMin;
}
