#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
#include " base-types.hpp"

namespace kaseev {
  class Parallelogram : public shape {
    Parallelogram(point_t A, point_t B, point_t C);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double nx, double ny);
    virtual void move(point_t nCenter);
    virtual void scale(double k, point_t pos);
  private:
    point_t A;
    point_t B;
    point_t C;
  };
}
#endif
