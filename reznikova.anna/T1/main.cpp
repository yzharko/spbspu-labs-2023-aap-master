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
      point_t center(x, y);
      try
      {
        Ring ring(center, r1, r2);
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
      point_t center(x0, y0);
      point_t point1(x1, y1);
      point_t point2(x2, y2);
      try
      {
        Regular regular(center, point1, point2);
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
      point_t leftpoint(lx, ly);
      point_t rightpoint(rx, ry);
      try
      {
        Rectangle rectangle(leftpoint, rightpoint);
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
