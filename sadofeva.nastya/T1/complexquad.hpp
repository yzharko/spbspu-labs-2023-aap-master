#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"

namespace sadofeva
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(Point_t& point1, Point_t& point2, Point_t & point3, Point_t& point4);
    double getArea() override;
    Rectangle_t getFrameRect() override;
    void move(double _x, double _y);
    void move(Point_t point) override;
    void scale(double k) override;
  private:
    Point_t _p1, _p2, _p3, _p4;
  }
};

#endif
