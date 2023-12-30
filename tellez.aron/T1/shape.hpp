#ifndef SHAPE_H
#define SHAPE_H
#include <stdexcept>
#include "base_types.h"
namespace tellez
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double delta_x, double delta_y) = 0;
    virtual void scale(double k);
  };
}
#endif
