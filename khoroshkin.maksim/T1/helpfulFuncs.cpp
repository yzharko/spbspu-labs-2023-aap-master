#include "helpfulFuncs.hpp"
#include <algorithm>
#include <cmath>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "complexquad.hpp"

void khoroshkin::implementRectangle(khoroshkin::Shape ** allFigures, size_t & figuresCounter)
{
  double x1, y1, x2, y2;
  if (std::cin >> x1 >> y1 >> x2 >> y2 && isRectangleCorrect(x1,y1,x2,y2))
  {
    allFigures[figuresCounter++] = new khoroshkin::Rectangle(point_t{x1, y1}, point_t{x2, y2});
  }
  else
  {
    std::cerr << "Error: wrong rectangle input\n";
  }
}

void khoroshkin::implementCircle(khoroshkin::Shape ** allFigures, size_t & figuresCounter)
{
  double x, y, radius;
  if (std::cin >> x >> y >> radius && radius > 0)
  {
    allFigures[figuresCounter++] = new khoroshkin::Circle(point_t{x, y}, radius);
  }
  else
  {
    std::cerr << "Error: wrong circle input\n";
  }
}

void khoroshkin::implementComplexquad(khoroshkin::Shape ** allFigures, size_t & figuresCounter)
{
  double x1, y1, x2, y2, x3, y3, x4, y4;
  if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 && isComplexquad(x1,y1,x2,y2,x3,y3,x4,y4))
  {
    allFigures[figuresCounter++] = new khoroshkin::Complexquad(point_t{x1, y1},\
    point_t{x2, y2}, point_t{x3, y3}, point_t{x4, y4});
  }
  else
  {
    std::cerr << "Error: wrong complexquad input\n";
  }
}

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

void khoroshkin::printResult(khoroshkin::Shape ** allFigures, size_t figuresCounter)
{
  double summOfFigures = 0;
  for (size_t i = 0; i < figuresCounter; ++i)
  {
    summOfFigures += allFigures[i]->getArea();
  }
  std::cout << summOfFigures << " ";
  for (size_t i = 0; i < figuresCounter; ++i)
  {
    std::cout << allFigures[i]->getFrameRect().pos.x - allFigures[i]->getFrameRect().width / 2 << " ";
    std::cout << allFigures[i]->getFrameRect().pos.y - allFigures[i]->getFrameRect().height / 2 << " ";
    std::cout << allFigures[i]->getFrameRect().pos.x + allFigures[i]->getFrameRect().width / 2 << " ";
    if (i == figuresCounter - 1)
    {
      std::cout << allFigures[i]->getFrameRect().pos.y + allFigures[i]->getFrameRect().height / 2;
    }
    else
    {
      std::cout << allFigures[i]->getFrameRect().pos.y + allFigures[i]->getFrameRect().height / 2 << " ";
    }
  }
  std::cout << "\n";
}

void khoroshkin::makeScale(khoroshkin::Shape ** allFigures, size_t figuresCounter, double x, double y, double scale)
{
  for (size_t i = 0; i < figuresCounter; ++i)
  {
    point_t initialPos = allFigures[i]->getFrameRect().pos;
    allFigures[i]->move({x, y});
    point_t diffPos;
    diffPos.x = fabs(initialPos.x - allFigures[i]->getFrameRect().pos.x) * scale;
    diffPos.y = fabs(initialPos.y - allFigures[i]->getFrameRect().pos.y) * scale;
    allFigures[i]->scale(scale);
    allFigures[i]->move(diffPos.x, diffPos.y);
  }
}
