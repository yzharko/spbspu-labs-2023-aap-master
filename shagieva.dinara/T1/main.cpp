#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include "resourceFunctions.hpp"
#include "dataFunctions.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "regular.hpp"

int main()
{
  size_t capacity = 10;
  shagieva::Shape ** shapes = new shagieva::Shape * [capacity];
  size_t shapeCount = 0;
  bool invalidFigureEntered = 0;
  bool scaleEntered = 0;

  while (std::cin)
  {
    if (shapeCount == capacity)
    {
      shagieva::increaseResource(shapes, capacity, shapeCount);
    }

    std::string figureType;
    std::cin >> figureType;

    if (figureType == "SCALE" && shapeCount == 0)
    {
      std::cerr << "Nothing to scale.\n";
      delete[] shapes;
      return 1;
    }

    if (figureType == "SCALE")
    {
      scaleEntered = true;
      break;
    }

    try
    {
      shagieva::parseFigure(figureType, std::cin, shapes, shapeCount);
    }
    catch(const std::invalid_argument & e)
    {
      invalidFigureEntered = true;
    }
  }

  if (!scaleEntered)
  {
    std::cerr << "Scale command is not entered.\n";
    shagieva::clearResource(shapes, shapeCount);
    return 1;
  }

  double scaleCenterX, scaleCenterY, scaleFactor;
  std::cin >> scaleCenterX >> scaleCenterY >> scaleFactor;

  std::cout << std::fixed << std::setprecision(1);

  double totalAreaBeforeScaling = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalAreaBeforeScaling += shapes[i]->getArea();
  }
  std::cout << totalAreaBeforeScaling << " ";

  shagieva::printFramePoints(shapes, shapeCount);

  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frameBeforeMoving = shapes[i]->getFrameRect();
    shapes[i]->move({ scaleCenterX, scaleCenterY });
    shagieva::rectangle_t frameAfterMoving = shapes[i]->getFrameRect();
    try
    {
      shapes[i]->scale(scaleFactor);
    }
    catch(std::invalid_argument & e)
    {
      std::cerr << "Invalid scale factor entered.\n";
      shagieva::clearResource(shapes, shapeCount);
      return 1;
    }
    double dx = (frameBeforeMoving.pos.x - frameAfterMoving.pos.x) * scaleFactor;
    double dy = (frameBeforeMoving.pos.y - frameAfterMoving.pos.y) * scaleFactor;
    shapes[i]->move(dx, dy);
  }

  double totalAreaAfterScaling = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalAreaAfterScaling += shapes[i]->getArea();
  }
  std::cout << totalAreaAfterScaling << " ";

  shagieva::printFramePoints(shapes, shapeCount);

  if (invalidFigureEntered)
  {
    std::cerr << "Invalid figure entered.\n";
  }

  shagieva::clearResource(shapes, shapeCount);

  return 0;
}
