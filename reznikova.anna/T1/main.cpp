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
      if (!std::cin)
      {
        std::cerr << "empty ring";
      }
      std::cout << "ring done";
      try
      {
        Ring ring(x, y, r1, r2);
      }
      catch(...)
      {
        
      }
    }
    
    else if (name == "REGULAR")
    {
      double x0, y0, x1, y1, x2, y2;
      std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
      std::cout << "reg";
      try
      {
        Regular regular(x0, y0, x1, y1, x2, y2);
      }
      catch(...)
      {
        
      }
    }
    
    else if (name == "RECTANGLE")
    {
      double lx, ly, rx, ry;
      std::cin >> lx >> ly >> rx >> ry;
      std::cout << "rect";
      try
      {
        Rectangle rectangle(lx, ly, rx, ry);
      }
      catch(...)
      {
        
      }
    }
    
    else
    {
      
    }
  }
  
  
  return 0;
}

