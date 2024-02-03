#include "outputArray.hpp"
#include <iostream>
#include <stdexcept>
//#include <fstream>
//#include <string>

int proselkov::linemin(int first, int second, int three)
{
  return ((((first < second) ? first : second) < three) ? ((first < second) ? first : second) : three);
}

int proselkov::locmin(int first, int second, int three, int four)
{
  return ((linemin(first, second, three) < four) ? (linemin(first, second, three)) : four);
}
int proselkov::CountLocMin(int matrix[], int rows, int cols)
{
  if ((rows <= 2) || (cols <= 2))
  {
    std::cout << "Error no CountLocMin.\n";
    return 0;
  }

  int Cnt_locMin = 0;
  for (int i = cols + 1; i < ((rows - 1) * cols); i++)
  {
    if ((i % cols != 0) && ((i + 1) % cols != 0))
    {
      int lineupmin = linemin(matrix[i - cols - 1], matrix[i - cols], matrix[i - cols + 1]);
      int linedownmin = linemin(matrix[i + cols - 1], matrix[i + cols], matrix[i + cols + 1]);
      if (matrix[i] < locmin(lineupmin,linedownmin,matrix[i - 1], matrix[i +  1]))
      {
        Cnt_locMin ++;
      }
    }
  }
  return Cnt_locMin;
}
