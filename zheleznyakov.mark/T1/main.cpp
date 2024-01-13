#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include "base-types.hpp"
#include "rectangle.hpp"

int main()
{
  using namespace zheleznyakov;
  size_t shapesSize = 1;
  Shape **shapes = new Shape *[shapesSize];
  size_t currentShapeIndex = 0;
  std::string currentFigureName;
  while (std::cin >> currentFigureName)
  {
    if (currentShapeIndex == shapesSize)
    {
      Shape **newShapes = new Shape *[shapesSize + 1];
      for (size_t i = 0; i < shapesSize; ++i)
      {
        newShapes[i] = shapes[i];
      }
      delete[] shapes;
      shapes = newShapes;
      shapesSize++;
    }
    if (currentFigureName == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      if ((std::cin >> x1 >> y1 >> x2 >> y2 && checkIsRectangleCoords(x1, y1, x2, y2)))
      {
        shapes[currentShapeIndex++] = new Rectangle(point_t{x1, y1}, point_t{x2, y2});
        std::cout << shapes[currentShapeIndex - 1]->getArea() << '\n';
      }
      else
      {
        std::cerr << "Error: cannot read RECTANGLE\n";
      }
      continue;
    }
  }

  return 0;
}
