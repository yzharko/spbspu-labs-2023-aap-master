#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace hohlova
{
  class Triangle : public Shape
  {
  public:
    Triangle() {};
    Triangle(point_t pos1, point_t pos2, point_t pos3);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t);
    virtual void move(double x, double y);
    virtual void scale(double k);
  private:
    point_t pos1_;
    point_t pos2_;
    point_t pos3_;
  };
}
#endif
