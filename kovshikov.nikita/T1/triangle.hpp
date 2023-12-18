#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include <cmath>

class Triangle: public Shape
{
public:
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t newPos)
  virtual void move(double xPlus, double yPlus)
  virtual void scale(double multiplier)
private:
  point_t vertexA;
  point_t vertexB;
  point_t vertexC;
  point_t normalH;
  double normal;
  double sideAb;
  double sideAc;
  double sideBc;
  point_t mindO;
  double sectionAo;
  point_t pos;
}

#endif
