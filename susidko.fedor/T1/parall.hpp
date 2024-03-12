#include "base-types.hpp"
#include "shape.hpp"
#ifndef PARALL_HPP
#define PARALL_HPP

class Parallelogram: public Shape
{
  public:
    Parallelogram() = delete;
    Parallelogram(point_t po1, point_t po2, point_t po3):
      po1_(po1),
      po2_(po2),
      po3_(po3)
    {}
    point_t getP1();
    point_t getP2();
    rectangle_t getFrameRect() override;
    double getArea() override;
    point_t getCenter();
    void move(double, double) override;
    void move(point_t) override;
    rectangle_t scale(double, double, double, rectangle_t) override;
  private:
    point_t po1_;
    point_t po2_;
    point_t po3_;
};

#endif
