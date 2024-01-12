#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include " base-types.hpp"

namespace kaseev {
  class Rectangle : public shape {
  public:
    Rectangle(point_t lPoint, point_t rPoint);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double nx, double ny);
    virtual void move(point_t center);
    virtual void scale(double k, point_t pos);
  private:
    point_t lPoint;
    point_t rPoint;
  };
}
#endif
