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
    void move(const double& x, const double& y);
    void move(const point_t& center);
    void newScale(const point_t& center, const double& k);
    void scale(const double& k);
  private:
    point_t center_;
    double radius_;
  };
}

#endif
