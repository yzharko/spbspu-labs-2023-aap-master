#include "set_figures.hpp"
#include <iostream>
#include <string>
#include <exception>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "regular.hpp"

reznikova::Shape * reznikova::setRectangle(std::istream & in, bool & ifNoErrors)
{
  double lx, ly, rx, ry;
  in >> lx >> ly >> rx >> ry;
  double width = rx - lx;
  double height = ry-ly;
  point_t pos = {lx + (rx - lx)/2, ly + (ry - ly)/2};
  rectangle_t rect = {width, height, pos};
  Shape * rectangle = nullptr;
  try
  {
    rectangle = new Rectangle(rect);
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << e.what();
    ifNoErrors = 0;
  }
  return rectangle;
}

reznikova::Shape * reznikova::setRing(std::istream & in, bool & ifNoErrors)
{
  double x, y, big_rad, small_rad;
  in >> x >> y >> big_rad >> small_rad;
  point_t center{x, y};
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

reznikova::Shape * reznikova::setRegular(std::istream & in, bool & ifNoErrors)
{
  double x0, y0, x1, y1, x2, y2;
  in >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
  point_t center{x0, y0};
  point_t pointA{x1, y1};
  point_t pointB{x2, y2};
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
