#include <iostream>
#include <string>
#include <iomanip>
#include "scaleFunc.hpp"

int main() {
  using namespace sukacheva;
  int ifScale = 0;
  std::string nameOfFigure = "";
  Shape* figures[1000]{};
  int index = 0;
  while (!std::cin.eof())
  {
    std::cin >> nameOfFigure;
    if (nameOfFigure == "RECTANGLE")
    {
      double x1, y1, x2, y2 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2;
      try
      {
        getRectangle(figures, x1, y1, x2, y2, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "CIRCLE")
    {
      double x, y, radius = 0;
      std::cin >> x >> y >> radius;
      try
      {
        getCircle(figures, x, y, radius, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "PARALLELOGRAM")
    {
      double x1, y1, x2, y2, x3, y3 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      try
      {
        getParallelogram(figures, x1, y1, x2, y2, x3, y3, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "SCALE")
    {
      ifScale = 1;
      double x, y, k = 0;
      std::cin >> x >> y >> k;
      if ( k <= 0 || index == 0)
      {
        std::cerr << "Incorrect input of figures";
        for (int i = 0; i < index; i++)
        {
          delete figures[i];
        }
        return 2;
      }
      else {
        point_t center{ x, y };
        double firstArea = 0;
        double newArea = 0;
        for (int i = 0; i < index; i++)
        {
          firstArea += figures[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << firstArea;

        for (int i = 0; i < index; i++)
        {
          rectangle_t frameRect = figures[i]->getFrameRect();
          getCoordinates(frameRect);
        }

        std::cout << "\n";

        for (int i = 0; i < index; i++)
        {
          figures[i]->scale(k);
          newArea += figures[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << newArea;

        for (int i = 0; i < index; i++)
        {
          rectangle_t newFrameRect = figures[i]->getFrameRect();
          newFrameRect.pos.x = (newFrameRect.pos.x - center.x) * k + center.x;
          newFrameRect.pos.y = (newFrameRect.pos.y - center.y) * k + center.y;
          getCoordinates(newFrameRect);
          delete figures[i];
        }
        std::cout << "\n";
        break;
      }
    }
  }
  if (ifScale == 0)
  {
    for (int i = 0; i < index; i++)
    {
      delete figures[i];
    }
    std::cerr << "No scale command";
    return 2;
  }
  return 0;
}
