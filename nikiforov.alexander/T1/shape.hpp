#ifndef SHAPE_HPP
#define SHAPE_HPP

namespace nikiforov
{
  class shape
  {
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(double x, double y) = 0;
    virtual void move(point_t center) = 0;
    virtual void scale(double ratio) = 0;
  };
}

#endif
