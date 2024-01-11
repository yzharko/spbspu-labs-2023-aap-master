#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace sukacheva
{
  class Circle : public Shape
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double x, double y);
    void move(point_t center);
    void newScale(point_t center, double k);
    void scale(double k);
  private:
    point_t center_;
    double radius_;
  };
}

#endif
