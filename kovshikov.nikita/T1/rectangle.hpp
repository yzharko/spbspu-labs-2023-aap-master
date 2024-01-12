#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <cmath>

namespace kovshikov
{
  class Rectangle: public Shape
  {
  public:
    ~Rectangle() = default override;
    Rectangle(point_t lowerLeft, point_t upperRight);
    double getArea() const override;  //const
    rectangle_t getFrameRect() const override;  // const
    void move(const point_t &newPos) override; //&const
    void move(double xPlus, double yPlus) override;
    void scale(double multiplier) override;
  private:
    point_t lowerLeft_;
    point_t upperRight_;
  };
}

#endif
