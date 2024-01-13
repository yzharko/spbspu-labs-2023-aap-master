#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

int main()
{
  struct CompositeShape
  {
    size_t shapes;
    size_t capacity;
    sobolevsky::Shape * shapeptrs;
  };

  sobolevsky::Shape ** figuers = new sobolevsky::Shape * [228];
  size_t counter = 0;

  std::string figureType;
  while (std::cin >> figureType)
  {
    if (figureType == "RECTANGLE")
    {
      double x1, x2, y1, y2;
      if ((std::cin >> x1 >> y1 >> x2 >> y2) && (x1 < x2) && (y1 < y2))
      {
        figuers[counter++] = new sobolevsky::Rectangle({x1, y1}, {x2, y2});
        std::cout << "rect\n";
      }
      else
      {
        std::cerr << "Wrong rectanglr\n";
      }
    }
    else if (figureType == "DIAMOND")
    {
      double x1, x2, x3, y1, y2, y3;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
      {
        figuers[counter++] = new sobolevsky::Diamond({x1, y1}, {x2, y2}, {x3, y3});
        std::cout << "diam\n";
      }
      else
      {
        std::cerr << "Wrong diamond\n";
      }
    }
    else if (figureType == "DIAMOND")
    {
      double x1, x2, x3, y1, y2, y3;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
      {
        figuers[counter++] = new sobolevsky::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
        std::cout << "param\n";
      }
      else
      {
        std::cerr << "Wrong parallelogram\n";
      }
    }
    else if (figureType == "SCALE")
    {
      std::cout << "scale\n";
    }
  }
}
