#include "set_figures.hpp"
#include <iostream>
#include <string>
#include <exception>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "regular.hpp"
#include "string_process.hpp"

reznikova::Shape * reznikova::setRectangle(std::string& line, bool & ifNoErrors)
{
  point_t leftpoint = getPointFromString(line);
  point_t rightpoint = getPointFromString(line);
  Shape * rectangle = nullptr;
  try
  {
    rectangle = new Rectangle(leftpoint, rightpoint);
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << e.what();
    ifNoErrors = 0;
  }
  return rectangle;
}

reznikova::Shape * reznikova::setRing(std::string& line, bool & ifNoErrors)
{
  point_t center = getPointFromString(line);
  double big_rad = getNextValue(line);
  double small_rad = getNextValue(line);
  Shape * ring = nullptr;
  try
  {
    ring = new Ring(center, big_rad, small_rad);
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << e.what();
    ifNoErrors = 0;
  }
  return ring;
}

reznikova::Shape * reznikova::setRegular(std::string& line, bool & ifNoErrors)
{
  point_t center = getPointFromString(line);
  point_t pointA = getPointFromString(line);
  point_t pointB = getPointFromString(line);
  Shape * regular = nullptr;
  try
  {
    regular = new Regular(center, pointA, pointB);
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << e.what();
    ifNoErrors = 0;
  }
  return regular;
}
