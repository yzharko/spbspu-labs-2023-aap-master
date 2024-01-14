#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea() = 0;
  virtual Rectangle_t getFrameRect() = 0;
  virtual void move(const char, double) = 0;
  virtual void move(double, double) = 0;
  virtual void scale(double) = 0;
};

#endif
