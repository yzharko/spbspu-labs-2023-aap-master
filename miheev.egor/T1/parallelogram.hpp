#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace miheev
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t center, point_t p1, point_t p2);

    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual move(point_t);
    virtual move(double dx, double dy);
    virtual void scale(double);

  private:
    point_t points_[4];
    point_t center_;
  }
}

#endif
