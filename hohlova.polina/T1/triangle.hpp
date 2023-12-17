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
    point_t pos1_ = { 0,0 };
    point_t pos2_ = { 0,0 };
    point_t pos3_ = { 0,0 };
    point_t pos_ = { 0,0 };
    double a_ = 0;
    double b_ = 0;
    double c_ = 0;
  };
}
#endif
