#include <iostream>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "regular.hpp"

int main()
{
  bool scale_command = 0;
  while (!std::cin.eof())
  {
    std::string name = "";
    std::cin >> name;

    if (name == "RING")
    {
      double x, y, r1, r2;
      std::cin >> x >> y >> r1 >> r2;
      reznikova::point_t center(x, y);
      try
      {
        reznikova::Ring ring(center, r1, r2);
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
      reznikova::point_t center(x0, y0);
      reznikova::point_t point1(x1, y1);
      reznikova::point_t point2(x2, y2);
      try
      {
        reznikova::Regular regular(center, point1, point2);
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
      reznikova::point_t leftpoint(lx, ly);
      reznikova::point_t rightpoint(rx, ry);
      try
      {
        reznikova::Rectangle rectangle(leftpoint, rightpoint);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
    }

    else if (name == "SCAlE")
    {
      scale_command = 1;
      double x, y, n;
      std::cin >> x >> y >> n;
      if (n <= 0)
      {
        std::cerr << "Negative Coeff Scale";
        return 1;
      }
    }

    else
    {
      std::cerr << "this figure is not supported\n";
    }
  }

  if (scale_command == 0)
  {
    std::cerr << "no scale command\n";
    return 1;
  }

  return 0;
}
