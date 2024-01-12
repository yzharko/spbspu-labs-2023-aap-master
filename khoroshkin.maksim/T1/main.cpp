#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "complexquad.hpp"
#include "helpfulFuncs.hpp"

int main()
{
  using namespace khoroshkin;
  size_t initialSize = 10;
  Shape ** allFigures = new Shape * [initialSize];
  size_t figuresCounter = 0;
  bool scaleCommandWas = false;
  std::string type;
  while (std::cin >> type)
  {
    if (figuresCounter == initialSize)
    {
      allFigures = expandArray(allFigures, figuresCounter, initialSize);
    }

    if (type == "RECTANGLE")
    {
      implementRectangle(allFigures, figuresCounter);
    }
    else if (type == "CIRCLE")
    {
      implementCircle(allFigures, figuresCounter);
    }
    else if (type == "COMPLEXQUAD")
    {
      implementComplexquad(allFigures, figuresCounter);
    }
    else if (type == "SCALE")
    {
      double x, y, scale;
      if (figuresCounter == 0)
      {
        std::cerr << "Error: nothing to scale";
        deleteFigures(allFigures, figuresCounter);
        return 1;
      }
      if (std::cin >> x >> y >> scale && scale > 0)
      {
        std::cout << std::fixed << std::setprecision(1);
        printResult(allFigures, figuresCounter);
        makeScale(allFigures, figuresCounter, x, y, scale);
        printResult(allFigures, figuresCounter);
        scaleCommandWas = true;
      }
      else
      {
        std::cerr << "Error: wrong scale input\n";
        deleteFigures(allFigures, figuresCounter);
        return 1;
      }
    }
    else if (std::all_of(type.begin(), type.end(), [](char c) { return std::isalpha(c); }))
    {
      std::cerr << "Error: unsupported figure\n";
      continue;
    }
    else
    {
      continue;
    }
  }
  deleteFigures(allFigures, figuresCounter);
  if (!scaleCommandWas)
  {
    std::cerr << "Error: missing scale command";
    return 1;
  }
  return 0;
}
