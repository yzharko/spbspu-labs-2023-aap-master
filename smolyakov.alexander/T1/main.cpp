#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "regular.hpp"
#include "compositeShape.hpp"
#include "shapeParsing.hpp"
#include "compositeShapeParameterPrinting.hpp"

int main()
{
  using namespace smolyakov;

  bool isScaleCommandEntered = false;
  bool isInvalidShapeEntered = false;
  size_t shapeCount = 0;
  Shape** shapes = new Shape*[1];

  while (std::cin)
  {
    std::string keyword;
    std::cin >> keyword;

    if (keyword == "SCALE")
    {
      isScaleCommandEntered = true;
      break;
    }

    try
    {
      if (parseShape(std::cin, keyword, shapes, shapeCount))
      {
        shapeCount++;
        Shape** newShapes = new Shape*[shapeCount+1];
        for (size_t i = 0; i < shapeCount; i++)
        {
          newShapes[i] = shapes[i];
        }
        delete[] shapes;
        shapes = newShapes;
      }
    }
    catch (const std::invalid_argument& e)
    {
      isInvalidFigureEntered = true;
    }
  }

  if (!isScaleCommandEntered)
  {
    std::cerr << "The SCALE command was not called.\n";
    return 1;
  }

  CompositeShape compositeShape = CompositeShape(shapeCount);
  for (size_t i = 0; i < shapeCount; i++)
  {
    compositeShape.addShape(*shapes[i]);
  }

  std::cout << std::fixed << std::setprecision(1) << compositeShape.getArea() << ' ';
  printCompositeShapeParameters(std::cout, compositeShape);

  point_t scaleCenter = {0};
  double scaleFactor;
  std::cin >> scaleCenter.x >> scaleCenter.y >> scaleFactor;
  compositeShape.scale(scaleCenter, scaleFactor);

  std::cout << std::fixed << std::setprecision(1) << compositeShape.getArea() << ' ';
  printCompositeShapeParameters(std::cout, compositeShape);

  if (isInvalidShapeEntered)
  {
    std::cerr << "An invalid shape was entered.\n";
  }

  return 0;
}
