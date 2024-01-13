#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
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
      }
      else
      {
        std::cerr << "Wrong parallelogram\n";
      }
    }
    else if (figureType == "SCALE")
    {
      double x, y, n;
      if (counter == 0)
      {
        std::cerr << "no figuers\n";
        return 1;
      }
      else if (std::cin >> x >> y >> n)
      {
        std::cout << std::fixed << std::setprecision(1);
        for (size_t i = 0; i < counter; i++)
        {
          std::cout << figuers[i]->getFrameRect().width * figuers[i]->getFrameRect().height << " ";
        }
      }
      else
      {
        std::cerr << "ты чето не то написал\n";
        return 1;
      }
    }
  }
  return 0;
}
