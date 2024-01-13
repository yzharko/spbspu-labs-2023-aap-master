#include <iostream>
#include <cctype>
#include <algorithm>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"

int main()
{
  using namespace zheleznyakov;
  size_t shapesSize = 1;
  Shape **shapes = new Shape *[shapesSize];
  size_t currentShapeIndex = 0;
  std::string currentFigureName = "";
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
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
      if (std::cin >> x1 >> y1 >> x2 >> y2 && checkIsRectangleCoords(x1, y1, x2, y2))
      {
        shapes[currentShapeIndex++] = new Rectangle(point_t{x1, y1}, point_t{x2, y2});
      }
      else
      {
        std::cerr << "Error: cannot read RECTANGLE\n";
      }
    }
    else if (currentFigureName == "DIAMOND")
    {
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 &&
          checkIsRighrTriangle(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3}))
      {
        shapes[currentShapeIndex++] = new Diamond(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3});
      }
      else
      {
        std::cerr << "Error: cannot read DIAMOND\n";
      }
    }
  }
  return 0;
}
