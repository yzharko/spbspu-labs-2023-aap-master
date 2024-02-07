#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <cmath>
#include <iostream>
using namespace maksimov;

class Rectangle : public Shape
{
public:
  Rectangle(double, double, double, double);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(const double&, const double&) override;
  virtual void move(const point_t& new_center) override;
  virtual void scale(double) override;
private:
  point_t pointLl = { 0, 0 };
  point_t pointUr = { 0, 0 };
  double width_ = 0;
  double height_ = 0;
  point_t pos_ = { 0, 0 };
};

#endif
