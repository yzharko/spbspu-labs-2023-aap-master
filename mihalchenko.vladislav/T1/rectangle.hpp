#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace mihalchenko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t pos1, point_t pos2);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(const double deltaX, const double deltaY) override;
    void scale(double scaleKoef) override;

  private:
    point_t pos1_;
    point_t pos2_;
    point_t pointCentre_;
    double width_;
    rectangle_t rectangle_;
  };
}
#endif
