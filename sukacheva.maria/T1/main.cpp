#include <iostream>
#include <string>
#include <iomanip>
#include "scaleFunc.hpp"

int main() {
  using namespace sukacheva;
  int ifScale = 0;
  std::string nameOfFigure = "";
  Shape* figures[1000]{};
  int index = 0;
  while (!std::cin.eof())
  {
    std::cin >> nameOfFigure;
    if (nameOfFigure == "RECTANGLE")
    {
      double x1, y1, x2, y2 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2;
      try
      {
        getRectangle(figures, x1, y1, x2, y2, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "CIRCLE")
    {
      double x, y, radius = 0;
      std::cin >> x >> y >> radius;
      try
      {
        getCircle(figures, x, y, radius, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "PARALLELOGRAM")
    {
      double x1, y1, x2, y2, x3, y3 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      try
      {
        getParallelogram(figures, x1, y1, x2, y2, x3, y3, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "SCALE")
    {
      ifScale = 1;
      double x, y, k = 0;
      std::cin >> x >> y >> k;
      if ( k <= 0 || index == 0)
      {
        std::cerr << "Incorrect input of figures";
        deleteArray(figures, index);
        return 2;
      }
      else {
        point_t center{ x, y };
        double firstArea = 0;
        double newArea = 0;
        getFirstArea(figures, index, firstArea);
        getCoordinatesBefore(figures, index);
        getScaledArea(figures, index, newArea, k);
        getCoordinatesAfter(figures, index, center, k);
        deleteArray(figures, index);
        break;
      }
    }
  }
  if (ifScale == 0)
  {
    deleteArray(figures, index);
    std::cerr << "No scale command";
    return 2;
  }
  return 0;
}
