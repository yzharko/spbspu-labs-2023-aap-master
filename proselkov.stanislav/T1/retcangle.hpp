#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
  public:
    Rectangle(point_t p1, point_t p2);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t newpoint);
    void move(double x, double y);
    void scale(double k);
  private:
  point_t p1;
  point_t p2;
};
#endif
