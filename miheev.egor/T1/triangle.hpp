#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace miheev
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t* points[3]);

    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t);
    virtual void move(double dx, double dy);
    virtual void scale(double);

  private:
    point_t* points_[3];
    point_t center_;
  };
};

#endif
