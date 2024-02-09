#include "base-types.hpp"
#include "shape.hpp"
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle: public Shape
{
  public:
    Rectangle() = delete;
    Rectangle(point_t po1, point_t po2):
      po1_(po1),
      po2_(po2)
    {}
    double getArea() override;
    point_t getP1();
    point_t getP2();
    rectangle_t getFrameRect() override;
    point_t getCenter();
    void move(double, double) override;
    void move(point_t) override;
    rectangle_t scale(double, double, double, rectangle_t) override;
    void print();
  private:
    point_t po1_;
    point_t po2_;
};

#endif
