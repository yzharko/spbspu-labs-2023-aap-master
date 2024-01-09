#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"

namespace khoroshkin
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(point_t first, point_t second, point_t third, point_t fourth);
    virtual double getArea() override;
    virtual rectangle_t getFrameRect() override;
    virtual void move(point_t newPoint) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double k) override;
  private:
    point_t pointA;
    point_t pointB;
    point_t pointC;
    point_t pointD;
    point_t cPoint;
    double side;
  };
}
#endif
