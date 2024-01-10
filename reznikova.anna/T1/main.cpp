#include <iostream>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "regular.hpp"

int main()
{
  while (!std::cin.eof())
  {
    std::string name = "";
    std::cin >> name;

    if (name == "RING")
    {
      double x, y, r1, r2;
      std::cin >> x >> y >> r1 >> r2;
      try
      {
        Ring ring(x, y, r1, r2);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
    }

    else if (name == "REGULAR")
    {
      double x0, y0, x1, y1, x2, y2;
      std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
      try
      {
        Regular regular(x0, y0, x1, y1, x2, y2);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
    }

    else if (name == "RECTANGLE")
    {
      double lx, ly, rx, ry;
      std::cin >> lx >> ly >> rx >> ry;
      try
      {
        Rectangle rectangle(lx, ly, rx, ry);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
    }

    else
    {
      std::cerr << "this figure is not supported\n";
    }
  }

  return 0;
}

