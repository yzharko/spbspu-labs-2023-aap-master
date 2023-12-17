#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>

namespace miheev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t* points);

    virtual double getArea() const;
    virtual Shape getFrameRect() const;
    virtual void move();
    virtual void scale();

    void calcParams();

  private:
    double width_;
    double height_;
    point_t points_[4];
  };
}

#endif
