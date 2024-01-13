#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <cmath>

namespace kovshikov
{
  class Rectangle: public Shape
  {
  public:
    virtual ~Rectangle() = default;
    Rectangle(point_t lowerLeft, point_t upperRight);
    virtual double getArea() const;  //const
    virtual rectangle_t getFrameRect() const;  // const
    virtual void move(const point_t &newPos); //&const
    virtual void move(double xPlus, double yPlus);
    virtual void scale(double multiplier);
  private:
    point_t lowerLeft_;
    point_t upperRight_;
  };
}

#endif
