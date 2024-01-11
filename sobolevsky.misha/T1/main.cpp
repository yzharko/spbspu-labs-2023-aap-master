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

  std::string figureType; 
  while (std::cin >> figureType)
  {
    if (figureType == "RECTANGLE")
    {
      double x1, x2, y1, y2;
      if ((std::cin >> x1 >> y1 >> x2 >> y2) && (x1 < x2) && (y1 < y2))
      {
        
      }
      else
      {
        std::cerr << "Wrong rectanglr\n";
      }
    }
  }
}
