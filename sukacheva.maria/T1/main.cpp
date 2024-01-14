#include <iostream>
#include <string>
#include <iomanip>
#include "scaleFunc.hpp"

int main() {
  using namespace sukacheva;
  int ifScale = 0;
  std::string nameOfFigure = "";
  Shape* figures[1000]{};
  Shape* scaledFigures[1000]{};
  int index = 0;
  while (!std::cin.eof())
  {
    std::cin >> nameOfFigure;
    if (nameOfFigure == "RECTANGLE")
    {
      point_t leftPoint = { 0, 0 };
      point_t rightPoint = { 0, 0 };
      std::cin >> leftPoint.x >> leftPoint.y >> rightPoint.x >> rightPoint.y;
      try
      {
        getRectangle(figures, scaledFigures, rightPoint, leftPoint, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "CIRCLE")
    {
      double radius = 0;
      point_t center = { 0, 0 };
      std::cin >> center.x >> center.y >> radius;
      try
      {
        getCircle(figures, scaledFigures, center, radius, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "PARALLELOGRAM")
    {
      point_t aPoint = { 0, 0 };
      point_t bPoint = { 0, 0 };
      point_t cPoint = { 0, 0 };
      std::cin >> aPoint.x >> aPoint.y >> bPoint.x >> bPoint.y
        >> cPoint.x >> cPoint.y;
      try
      {
        getParallelogram(figures, scaledFigures, aPoint, bPoint, cPoint, index);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "SCALE")
    {
      ifScale = 1;
      double k = 0;
      point_t center = { 0, 0 };
      std::cin >> center.x >> center.y >> k;
      if ( index == 0)
      {
        std::cerr << "The figures were not entered\n";
        deleteArray(figures, index);
        return 2;
      }
      else {
        try
        {
          scaleCheck(scaledFigures, index, k);
        }
        catch (const std::logic_error& e)
        {
          std::cerr << "Incorrect scaling factor\n";
          deleteArray(figures, index);
          deleteArray(scaledFigures, index);
          return 1;
        }
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
