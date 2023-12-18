#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace popov
{
  class Rectangle : public Shape
  {
    public:
    float getArea() override;
    rectangle_t getFrameRect() override;
    void move(point_t pos) override;
    void move(point_t x, point_t y) override;
    void scale(n) override;
  };
}
#endif
