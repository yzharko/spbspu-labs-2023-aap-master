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

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double dx, double dy) override;
    void scale(double) override;

  private:
    point_t* points[4];
    double width_;
    double height_;
    point_t center_;
  };
}

#endif
