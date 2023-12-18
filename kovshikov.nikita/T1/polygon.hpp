#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <stddef>

class Polygon:
{
public:
  virtual double getArea() = 0;
private:
  size_t vertexes = 3;
  point_t points[vertexes] = {};
}

#endif
