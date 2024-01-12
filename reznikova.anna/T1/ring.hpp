#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Ring : public Shape
  {
  public:
    Ring(point_t center, double r1, double r2);
    ~Ring() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double& dx, const double& dy) override;
    void move(const point_t& new_center) override;
    void scale(const double n) override;
  private:
    point_t center_;
    double big_rad_;
    double small_rad_;
  };
}

#endif
