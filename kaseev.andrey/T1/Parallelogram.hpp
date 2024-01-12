#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
#include " base-types.hpp"

namespace kaseev {
  class Parallelogram : public shape {
    Parallelogram(point_t A, point_t B, point_t C);

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
