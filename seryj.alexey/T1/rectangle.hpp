#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include <cmath>
class Rectangle : public Shape
{
public:
  Rectangle() {};
  Rectangle(point_t lp, point_t rp) : left_point_(lp), right_point_(rp)
  {
    pos_.x = (left_point_.x + right_point_.x) / 2;
    pos_.y = (left_point_.y + right_point_.y) / 2;
    width_ = abs(left_point_.x - right_point_.x);
    height_ = abs(left_point_.y - right_point_.y);
  }
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t);
  virtual void move(double x, double y);
  virtual void scale(double k);
private:
  point_t left_point_ = { 0, 0 };
  point_t right_point_ = { 0,0 };
  point_t pos_ = { 0,0 };
  double width_ = 0;
  double height_ = 0;
};
#endif
