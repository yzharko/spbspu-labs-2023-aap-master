#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace sukacheva
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(point_t A, point_t B, point_t C);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const double& x, const double& y);
    void move(const point_t& center);
  private:
    void scaling(double k) override;
    point_t A_;
    point_t B_;
    point_t C_;
  };
}

#endif
