#include <cmath>
#include <iostream>
#include <string>
#include "rectangle.hpp"
#include "usefulFunctions.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

int main()
{
  using namespace miheev;
  size_t shapesSize = 5;
  Shape** shapes = new Shape*[shapesSize];
  size_t figsNow = 0;

  while(std::cin)
  {
    std::string figName = "";
    std::cin >> figName;
    if (figsNow >= shapesSize)
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
        shapes[figsNow++] = new Rectangle(point_t(x1, y1), point_t(x2, y2));
      }
    }
    else if (figName == "TRIANGLE")
    {
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 && validateTriangle({x1, y1}, {x2, y2}, {x3, y3}))
      {
        shapes[figsNow++] = new miheev::Triangle({x1, y1}, {x2, y2}, {x3, y3});
      }

    }
    else if (figName == "PARALLELOGRAM")
    {
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 && validateTriangle({x1, y1}, {x2, y2}, {x3, y3}))
      {
        shapes[figsNow++] = new miheev::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
      }
    }

    if (figName == "SCALE")
    {
      double x0 = 0, y0 = 0, k = 0, sumAreaBefore = 0, sumAreaAfter = 0;
      if (std::cin >> x0 >> y0 >> k)
      {
        rectangle_t* rectsBefore = new rectangle_t[figsNow];
        size_t indexBefore = 0;
        rectangle_t* rectsAfter = new rectangle_t[figsNow];
        size_t indexAfter = 0;

        for (size_t i = 0; i < figsNow; i++)
        {
          point_t scaleCenter(x0, y0);
          Shape* shape = shapes[i];
          sumAreaBefore += shape->getArea();
          rectangle_t rectBefore = shape->getFrameRect();
          rectsBefore[indexBefore++] = rectBefore;

          shape->move(scaleCenter);
          rectangle_t rectAfter = shape->getFrameRect();
          double dx = rectBefore.pos.x - rectAfter.pos.x;
          double dy = rectBefore.pos.y - rectAfter.pos.y;
          shape->move(dx, dy);
          shape->scale(k);
          rectsAfter[indexAfter++] = shape->getFrameRect();
          sumAreaAfter += shape->getArea();
        }
        miheev::printCurrentState(sumAreaBefore, rectsBefore, figsNow);
        miheev::printCurrentState(sumAreaAfter, rectsAfter, figsNow);
        delete[] rectsBefore;
        delete[] rectsAfter;
        for (size_t i = 0; i < figsNow; i++)
        {
          std::cout << i << '\n';
          //std::cout << shapes[i]->getArea();
          delete shapes[i];
        }
        delete[] shapes;
        return 0;
      }
    }
  }
}
