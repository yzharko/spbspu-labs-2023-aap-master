#ifndef RING_HPP
#define RING_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace likhachev
{
  class Ring: public Shape {
  public:
    Ring(point_t pos, double outerRad, double innerRad);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& offset);
    virtual void move(double offsetX, double offsetY);
    virtual void scale(double multiplier);
  private:
    double outerRad_;
    double innerRad_;
    point_t pos_;

    point_t getPos() const;
    double getOuterRad() const;
    double getInnerRad() const;
  };
}
#endif
