#ifndef SHAPE_HPP
#define SHAPE_HPP

namespace miheev
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual Shape getFrameRect() const = 0;
    virtual void move() = 0;
    virtual void scale() = 0;
  };
}

#endif
