#include <cmath>
#include <iostream>
#include <string>
#include "rectangle.hpp"


int main()
{
  using namespace miheev;
  size_t shapesSize = 5;
  Shape** shapes = new Shape*[shapesSize];
  size_t firstFree = 0;

  while(std::cin)
  {
    std::string figName;
    std::cin >> figName;
    std::cout << "Name is " << figName << "\n";
    if (firstFree >= shapesSize)
    {
      const size_t extraSize = 5;
      Shape** temp = new Shape*[shapesSize + extraSize];
      for (size_t i = 0; i < shapesSize; i++)
      {
        temp[i] = shapes[i];
      }
      delete[] shapes;
      shapes = temp;
      shapesSize += extraSize;
      temp = nullptr;
    }

    if (figName == "RECTANGLE")
    {
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
      if(std::cin >> x1 >> y1 >> x2 >> y2 && x2 > x1 && y2 > y1)
      {
        shapes[firstFree++] = new Rectangle(point_t(x1, y1), point_t(x2, y2));
      }
    }
    else if (figName == "TRIANGLE")
    {

    }
    else if (figName == "PARALLELOGRAM")
    {

    }
    else
    {
      continue;
    }

    if (figName == "SCALE")
    {
      double x0 = 0, y0 = 0, k = 0, sumArea = 0;
      if (std::cin >> x0 >> y0 >> k)
      {
        for (size_t i = 0; i < firstFree; i++)
        {
          point_t scaleCenter(x0, y0);
          Shape* shape = shapes[i];
          sumArea += shape->getArea();

          rectangle_t rectBefore = shape->getFrameRect();
          shape->move(scaleCenter);
          rectangle_t rectAfter = shape->getFrameRect();
          double dx = rectBefore.pos.x - rectAfter.pos.x;
          double dy = rectBefore.pos.y - rectAfter.pos.y;

          shape->move(dx, dy);
          shape->scale(k);
        }
      }
    }
  }
  return 0;
}