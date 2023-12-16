#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "shape.hpp"
#include "square.hpp"
class Regular : public Shape
{
public:
  Regular(point_t a, point_t b, point_t c);
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t);
  virtual void move(double x, double y);
  virtual void scale(double k);
private:
  Square square_;
};
#endif