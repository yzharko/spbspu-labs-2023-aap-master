#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace batunov
{
  class diamond : public shape
  {
  public:
    diamond(const point_t& point1, const point_t& point2, const point_t& point3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scale(double coeff) override;
  private:
    point_t point1_;
    point_t point2_;
    point_t point3_;
  };
}

#endif
