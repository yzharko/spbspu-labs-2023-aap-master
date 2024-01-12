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

void sukacheva::getRectangle(Shape* figures[], double x1, double y1, double x2, double y2, int& index)
{
  point_t point1 = { x1, y1 };
  point_t point2 = { x2, y2 };
  Shape* rectangle = new sukacheva::Rectangle(point2, point1);
  figures[index] = rectangle;
  index += 1;
}

void sukacheva::getCircle(Shape* figures[], double x, double y, double radius, int& index)
{
  point_t point1 = { x, y };
  Shape* circle = new Circle(point1, radius);
  figures[index] = circle;
  index += 1;
}

void sukacheva::getParallelogram(Shape* figures[], double x1, double y1, double x2, double y2, double x3, double y3, int& index)
{
  point_t point1 = { x1, y1 };
  point_t point2 = { x2, y2 };
  point_t point3 = { x3, y3 };
  Shape* parallelogram = new Parallelogram(point1, point2, point3);
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
