#include "helpfulFuncs.hpp"
#include <algorithm>

bool khoroshkin::isRectangleCorrect(double x1, double y1, double x2, double y2)
{
  return x1 < x2 && y1 < y2;
}

bool khoroshkin::isComplexquad(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
  int quaterA = (x1 > 0) ? ((y1 >= 0) ? 1 : 4) : ((y1 > 0) ? 2 : 3);
  int quaterB = (x2 > 0) ? ((y2 >= 0) ? 1 : 4) : ((y2 > 0) ? 2 : 3);
  int quaterC = (x3 > 0) ? ((y3 >= 0) ? 1 : 4) : ((y3 > 0) ? 2 : 3);
  int quaterD = (x4 > 0) ? ((y4 >= 0) ? 1 : 4) : ((y4 > 0) ? 2 : 3);

  return (quaterA != quaterB && quaterB != quaterC && quaterC != quaterD && quaterD != quaterA);
}

khoroshkin::Shape ** khoroshkin::expandArray(Shape ** array, size_t currSize, size_t newSize)
{
  currSize += newSize;
  Shape ** tempStorage = new Shape * [currSize];
  std::copy(array, array + currSize - newSize, tempStorage);
  for (size_t i = 0; i < currSize - newSize; ++i)
  {
    delete array[i];
  }
  delete[] array;
  array = tempStorage;
  return array;

}

void khoroshkin::deleteFigures(khoroshkin::Shape ** allFigures, size_t figuresCounter)
{
  for (size_t i = 0; i < figuresCounter; ++i)
  {
    delete allFigures[i];
  }
  delete[] allFigures;
}
