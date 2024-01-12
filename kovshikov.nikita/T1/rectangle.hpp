#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <cmath>

namespace kovshikov
{
  class Rectangle: public Shape
  {
  public:
    override ~Rectangle() = default;
    Rectangle(point_t lowerLeft, point_t upperRight);
    override double getArea() const;  //const
    override rectangle_t getFrameRect() const;  // const
    override void move(const point_t &newPos); //&const
    override void move(double xPlus, double yPlus);
    override void scale(double multiplier);
  private:
    point_t lowerLeft_;
    point_t upperRight_;
  };
}

#endif
