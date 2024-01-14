#include "scaleFunc.hpp"
#include <iostream>
#include <iomanip>
#include "rectangle.hpp"
#include "circle.hpp"
#include "parallelogram.hpp"

void sukacheva::getCoordinates(rectangle_t frameRect)
{
  double x1, y1, x2, y2 = 0;
  x1 = frameRect.pos.x - frameRect.width / 2.0;
  y1 = frameRect.pos.y - frameRect.height / 2.0;
  x2 = frameRect.pos.x + frameRect.width / 2.0;
  y2 = frameRect.pos.y + frameRect.height / 2.0;
  std::cout << std::fixed << std::setprecision(1) << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
}

void sukacheva::getCoordinatesBefore(Shape* figures[], int index)
{
  for (int i = 0; i < index; i++)
  {
    rectangle_t frameRect = figures[i]->getFrameRect();
    getCoordinates(frameRect);
  }
  std::cout << "\n";
}

void sukacheva::getCoordinatesAfter(Shape* figures[], int index, point_t center, double k)
{
  for (int i = 0; i < index; i++)
  {
    rectangle_t newFrameRect = figures[i]->getFrameRect();
    newFrameRect.pos.x = (newFrameRect.pos.x - center.x) * k + center.x;
    newFrameRect.pos.y = (newFrameRect.pos.y - center.y) * k + center.y;
    getCoordinates(newFrameRect);
  }
  std::cout << "\n";
}

void sukacheva::getRectangle(Shape* figures[], point_t rightPoint, point_t leftPoint, int& index)
{
  Shape* rectangle = new sukacheva::Rectangle(rightPoint, leftPoint);
  Shape* rectangleCheck = new sukacheva::Rectangle(rightPoint, leftPoint);
  figures[index] = rectangle;
  index += 1;
}

void sukacheva::getCircle(Shape* figures[], point_t center, double radius, int& index)
{
  Shape* circle = new Circle(center, radius);
  Shape* circleCheck = new Circle(center, radius);
  figures[index] = circle;
  index += 1;
}

void sukacheva::getParallelogram(Shape* figures[], point_t aPoint, point_t bPoint, point_t cPoint, int& index)
{
  Shape* parallelogram = new Parallelogram(aPoint, bPoint, cPoint);
  Shape* parallelogramCheck = new Parallelogram(aPoint, bPoint, cPoint);
  figures[index] = parallelogram;
  index += 1;
}

void sukacheva::deleteArray(Shape* figures[], int index)
{
  for (int i = 0; i < index; i++)
  {
    delete figures[i];
  }
}

void sukacheva::getFirstArea(Shape* figures[], int index, double& firstArea)
{
  for (int i = 0; i < index; i++)
  {
    firstArea += figures[i]->getArea();
  }
  std::cout << std::fixed << std::setprecision(1) << firstArea;
}

void sukacheva::getScaledArea(Shape* figures[], int index, double& scaledArea, double k)
{
  for (int i = 0; i < index; i++)
  {
    figures[i]->scale(k);
    scaledArea += figures[i]->getArea();
  }
  std::cout << std::fixed << std::setprecision(1) << scaledArea;
}

