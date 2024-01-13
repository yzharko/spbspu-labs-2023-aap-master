#include "dataFunctions.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "regular.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <iostream>
#include <iomanip>

void shagieva::parseFigure(std::string figureType, std::istream & input, shagieva::Shape ** shapes, size_t & shapeCount)
{
  if (figureType == "RECTANGLE")
  {
    double x1, y1, x2, y2;
    input >> x1 >> y1 >> x2 >> y2;
    try
    {
      shapes[shapeCount++] = new shagieva::Rectangle(shagieva::point_t{ x1, y1 }, shagieva::point_t{ x2, y2 });
    }
    catch(const std::invalid_argument & e)
    {
      throw std::invalid_argument("Invalid figure entered");
    }
  }

  else if (figureType == "COMPLEXQUAD")
  {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    try
    {
      shapes[shapeCount++] = new shagieva::Complexquad(shagieva::point_t{ x1, y1 },
        shagieva::point_t{ x2, y2 },
        shagieva::point_t{ x3, y3 },
        shagieva::point_t{ x4, y4 });
    }
    catch(const std::invalid_argument & e)
    {
      throw std::invalid_argument("Invalid figure entered");
    }
  }

  else if (figureType == "REGULAR")
  {
    double x1, y1, x2, y2, x3, y3;
    input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    try
    {
      shapes[shapeCount++] = new shagieva::Regular(shagieva::point_t{ x1, y1 }, shagieva::point_t{ x2, y2 },
        shagieva::point_t{ x3, y3 });
    }
    catch(const std::invalid_argument & e)
    {
      throw std::invalid_argument("Invalid figure entered");
    }
  }

  else
  {
    throw std::invalid_argument("Invalid figure entered");
  }
}

void shagieva::printFramePoints(const shagieva::Shape * const * const shapes, const size_t & shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << std::fixed << std::setprecision(1)
              << frame.pos.x - frame.width / 2 << " "
              << frame.pos.y - frame.height / 2 << " "
              << frame.pos.x + frame.width / 2 << " "
              << frame.pos.y + frame.height / 2
              << ((i == (shapeCount - 1)) ? "\n" : " ");
  }
}

void shagieva::printTotalArea(const shagieva::Shape * const * const shapes, const size_t & shapeCount)
{
  double totalArea = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalArea += shapes[i]->getArea();
  }
  std::cout << std::fixed << std::setprecision(1) << totalArea << " ";
}
