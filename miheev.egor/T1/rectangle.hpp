#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>

namespace miheev
{
  class Rectangle: public Shape
  {
  private:
    point_t* points_;
    double width_;
    double height_;
    point_t center_;

  public:
    Rectangle(point_t bottomLeft, point_t topRight);
    ~Rectangle() override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double dx, double dy) override;
    void scale(double) override;
  };
}

#endif
