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
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t);
    virtual void move(double dx, double dy);
    virtual void scale(double);

    void calcParams();

  private:
    double width_;
    double height_;
    point_t points_[4];
    bool isValid;
  };
}

#endif
