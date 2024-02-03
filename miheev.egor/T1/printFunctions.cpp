#include "printFunctions.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

namespace miheev
{
  double roundWithDeep(double x, size_t deepness)
  {
    return std::round(x * std::pow(10, deepness))/std::pow(10, deepness);
  }

  void printPoint(double x, double y)
  {
    std::cout << std::fixed << std::setprecision(1) << roundWithDeep(x, 1) << " " << roundWithDeep(y, 1);
  }

  void printRect(rectangle_t rect)
  {
    printPoint(rect.pos.x - rect.width/2, rect.pos.y - rect.height/2);
    std::cout << " ";
    printPoint(rect.pos.x + rect.width/2, rect.pos.y + rect.height/2);
  }

  void printCurrentState(double sumArea, rectangle_t* rects, size_t rectsAmount)
  {
    std::cout << std::fixed << std::setprecision(1) <<  sumArea << " ";
    for (size_t i = 0; i < rectsAmount; i++)
    {
      printRect(rects[i]);
      if (i != rectsAmount - 1)
      {
        std::cout << " ";
      }
    }
    std::cout << '\n';
  }
}
