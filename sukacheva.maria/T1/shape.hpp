#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace sukacheva
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const double& x, const double& y) = 0;
    virtual void move(const point_t& center) = 0;
    void scale(double k);
  private:
    virtual void scaling(double k) = 0;
  };
}
#endif
