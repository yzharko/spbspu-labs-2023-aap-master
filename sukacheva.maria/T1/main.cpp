#include <iostream>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "Circle.hpp"
#include "Parallelogram.hpp"
#include "Rectangle.hpp"

int main() {
  std::string nameOfFigure = "";
  while (!std::cin.eof())
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
        point_t point1 = { x1, y1 };
        point_t point2 = { x2, y2 };
        Shape* rectangle = new Rectangle(point1, point2);
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
        point_t point1 = { x, y };
        Shape* circle = new Circle(point1, radius);
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
        point_t point1 = { x1, y1 };
        point_t point2 = { x2, y2 };
        point_t point3 = { x3, y3 };
        Shape* parallelogram = new Parallelogram(point1, point2, point3);
        parallelogram->getArea();
        parallelogram->getFrameRect();
        delete[] parallelogram;
      }
    }
  }
  return 0;
}
