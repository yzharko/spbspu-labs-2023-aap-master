#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"

int main()
{
  using namespace hohlova;
  std::string figure = "";
  size_t figuresCount = 0;
  Shape** figures = new Shape * [100] {};
  while (!std::cin.eof())
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      double lx, ly, rx, ry;
      std::cin >> lx >> ly >> rx >> ry;
      if (!std::cin)
      {
        std::cerr << "cannot read an input\n";
      }
      point_t lpos(lx, ly);
      point_t rpos(rx, ry);
      Rectangle rectangle(lpos, rpos);
    }
    else if (figure == "SQUARE")
    {
      double x, y, side;
      std::cin >> x >> y >> side;
      if (!std::cin)
      {
        std::cerr << "cannot read an input\n";
      }
      figures[figuresCount] = new Square({ x, y }, side);
      try
      {
        figures[figuresCount]->getArea();
      }
      catch (const std::exception& ex)
      {
        std::cerr << ex.what();
        delete[] figures[figuresCount];
        figuresCount--;
      }
      figuresCount++;
    }
    else if (figure == "TRIANGLE")
    {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (!std::cin)
      {
        std::cerr << "cannot read an input\n";
      }
      figures[figuresCount] = new Triangle({ x1, y1 }, { x2, y2 }, { x3, y3 });
      try
      {
        figures[figuresCount]->getArea();
      }
      catch (const std::exception& ex)
      {
        std::cerr << ex.what();
        delete[] figures[figuresCount];
        figuresCount--;
      }
      figuresCount++;
    }
    else if (figure == "\0")
    {
      std::cerr << "no figure\n";
      return 1;
    }
    return 0;
  }
}
