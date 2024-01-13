#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
#include " base-types.hpp"

namespace kaseev {
  class Ellipce : public shape {
  public:
    Ellipce(point_t center, double vertRad, double gorRad);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double nx, double ny);
    virtual void move(point_t nCenter);
    virtual void scale(double k, point_t pos);
  private:
    point_t center;
    double vertRad;
    double gorRad;
  };
}
#endif
