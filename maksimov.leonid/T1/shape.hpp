#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual float getArea() = 0;
  virtual Rectangle_t getFrameRect() = 0;
  virtual void move(const char, float) = 0;
  virtual void move(float, float) = 0;
  virtual void scale(float) = 0;
};

#endif
