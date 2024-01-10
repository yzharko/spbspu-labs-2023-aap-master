#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace mihalchenko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &pos1, const point_t &pos2);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;

    virtual void move(const point_t &point) override;
    virtual void move(const double dx, const double dy) override;
    virtual double scale(double koef) override;

  private:
    point_t pos_;
    double width_;
    double height_;
  };
}
#endif
