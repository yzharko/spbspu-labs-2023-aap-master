#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "shape.hpp"
namespace seryj {
  class Regular : public Shape
  {
  public:
    Regular(point_t a, point_t b, point_t c);
    virtual double getArea()const;
    virtual rectangle_t getFrameRect()const;
    virtual void move(point_t);
    virtual void move(double x, double y);
    virtual void scale(double k);
  private:
    int n_ = 0;
    double hypotenuse_ = 0;
    double cathetus_ = 0;
    double side_ = 0;
    point_t pos_ = { 0,0 };
  };
}
#endif
