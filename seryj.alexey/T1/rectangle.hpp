#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace seryj {
  class Rectangle : public Shape
  {
  public:
    Rectangle() {};
    Rectangle(point_t lp, point_t rp);
    virtual double getArea()const;
    virtual rectangle_t getFrameRect()const;
    virtual void move(const point_t&);
    virtual void move(const double& x, const double& y);
    virtual void scale(const double&);
  private:
    point_t left_point_ = { 0, 0 };
    point_t right_point_ = { 0,0 };
    point_t pos_ = { 0,0 };
    double width_ = 0;
    double height_ = 0;
  };
}
#endif
