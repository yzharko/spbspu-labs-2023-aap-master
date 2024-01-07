#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <stddef>
#include <algorithm>

class Polygon: public Shape
{
public:
  Polygon(size_t num, point_t points[num]);
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t newPos);
  virtual void move(double xPlus, double yPlus);
  virtual void scale(double multiplier);
  point_t getPos();
private:
  size_t num_ = 3;
  point_t points_[num_] = {};
}

#endif
