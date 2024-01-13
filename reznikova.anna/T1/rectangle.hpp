#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(rectangle_t rect);
    ~Rectangle() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double& dx, const double& dy) override;
    void move(const point_t& new_center) override;
    void scale(const double n) override;
  private:
    rectangle_t rectangle_;
  };
}

#endif
