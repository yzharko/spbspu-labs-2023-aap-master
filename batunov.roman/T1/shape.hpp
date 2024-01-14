#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace batunov
{
  class shape
  {
  public:
    virtual double batunov::getArea();
    virtual batunov::rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double coeff) = 0;
  };
}

#endif
