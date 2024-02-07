#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"

namespace khoroshkin
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(point_t first, point_t second, point_t third, point_t fourth);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & newPoint) override;
    void move(double dx, double dy) override;
  private:
    void doScale(double k) override;
    point_t pointA;
    point_t pointB;
    point_t pointC;
    point_t pointD;
    point_t centerPoint;
  };
}
#endif
