#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include <cmath>
#include <algorithm>

class Triangle: public Shape
{
public:
  Triangle(point_t vertexA, point_t vertexB, point_t vertexC);
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t newPos)
  virtual void move(double xPlus, double yPlus)
  virtual void scale(double multiplier)
private:
  point_t vertexA_;
  point_t vertexB_;
  point_t vertexC_;
}

#endif
