#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Regular : public Shape
  {
  public:
    Regular(point_t center, point_t pointA, point_t pointB);
    ~Regular() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double& dx, const double& dy) override;
    void move(const point_t& new_center) override;
    void scale(const double n) override;
  private:
    point_t center_;
    point_t pointA_;
    point_t pointB_;
    double inscribed_rad;
    double circum_rad;
    double num_sides;
  };
}

#endif
