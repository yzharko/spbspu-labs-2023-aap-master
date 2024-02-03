#include "shapeParsing.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "regular.hpp"

bool smolyakov::parseShape(std::istream& stream, std::string type, smolyakov::Shape** shapes, size_t shapeCount)
{
  bool added = true;
  if (type == "RECTANGLE")
  {
    point_t bottomLeft = {0};
    point_t upperRight = {0};
    stream >> bottomLeft.x >> bottomLeft.y >> upperRight.x >> upperRight.y;
    try
    {
      shapes[shapeCount] = new Rectangle(bottomLeft, upperRight);
    }
    catch (const std::invalid_argument& e)
    {
      throw std::invalid_argument("Invalid rectangle parameters.");
    }
  }
  else if (type == "CIRCLE")
  {
    point_t center = {0};
    double radius;
    stream >> center.x >> center.y >> radius;
    try
    {
      shapes[shapeCount] = new Circle(center, radius);
    }
    catch (const std::invalid_argument& e)
    {
      throw std::invalid_argument("Invalid circle parameters.");
    }
  }
  else if (type == "REGULAR")
  {
    point_t center = {0};
    point_t second = {0};
    point_t third = {0};
    stream >> center.x >> center.y >> second.x >> second.y >> third.x >> third.y;
    try
    {
      shapes[shapeCount] = new Regular(center, second, third);
    }
    catch (const std::invalid_argument& e)
    {
      throw std::invalid_argument("Invalid regular polygon parameters.");
    }
  }
  else
  {
    added = false;
  }
  return added;
}
