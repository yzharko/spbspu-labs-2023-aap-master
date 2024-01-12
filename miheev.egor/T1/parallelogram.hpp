#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace miheev
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t center, point_t p1, point_t p2);
    ~Parallelogram();

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double dx, double dy) override;
    void scale(double) override;

  private:
    point_t* points_;
    point_t center_;
  };
}

#endif
