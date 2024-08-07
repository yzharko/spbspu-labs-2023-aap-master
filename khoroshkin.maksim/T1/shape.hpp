#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
#include <iostream>
#include <stdexcept>

namespace khoroshkin
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & newPoint) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double k);
  private:
    virtual void doScale(double k) = 0;
  };
}
#endif
