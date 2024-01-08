#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <cstddef>
#include <algorithm>

class Polygon: public Shape
{
public:
  Polygon(size_t num, point_t * points);
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t newPos);
  virtual void move(double xPlus, double yPlus);
  virtual void scale(double multiplier);
  point_t getPos();
private:
  size_t num_;
  point_t * points_ = nullptr;
};

#endif
