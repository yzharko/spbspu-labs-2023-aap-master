#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace batunov
{
  class rectangle : public shape
  {
  public:
    rectangle(const rectangle_t& rect);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scale(double coeff) override;
  private:
    rectangle_t rect_;
  };
}

#endif
