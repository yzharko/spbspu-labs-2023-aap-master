#include <iostream>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "Circle.hpp"
#include "Parallelogram.hpp"
#include "Rectangle.hpp"

int main() {
  std::string nameOfFigure = "";
  do
  {
    std::cin >> nameOfFigure;
    if (nameOfFigure == "RECTANGLE")
    {
      double x1, y1, x2, y2 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2;
      if (!std::cin)
      {
        std::cerr << "Wrong input";
      }
      else
      {
        Shape* rectangle = new Rectangle({ x1, y1 }, { x2, y2 });
        rectangle->getArea();
        rectangle->getFrameRect();
        delete[] rectangle;
      }
    }
    else if (nameOfFigure == "CIRCLE")
    {
      double x, y, radius = 0;
      std::cin >> x >> y >> radius;
      if (!std::cin || radius < 0)
      {
        std::cerr << "Wrong input";
      }
      else
      {
        Shape* circle = new Circle({ x, y }, radius);
        circle->getArea();
        circle->getFrameRect();
        delete[] circle;
      }
    }
    else if (nameOfFigure == "PARALLELOGRAM")
    {
      double x1, y1, x2, y2, x3, y3 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (!std::cin)
      {
        std::cerr << "Wrong input";
      }
      else
      {
        Shape* parallelogram = new Parallelogram({ x1, y1 }, { x2, y2 }, { x3, y3 });
        parallelogram->getArea();
        parallelogram->getFrameRect();
        delete[] parallelogram;
      }
    }
  } while (nameOfFigure != "SCALE");
  return 0;
}
