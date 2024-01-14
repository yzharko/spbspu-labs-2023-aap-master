#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <cmath>
#include <iostream>

class Rectangle : public Shape
{
public:
  Rectangle(double, double, double, double);
  virtual double getArea() override;
  virtual Rectangle_t getFrameRect() override;
  virtual void move(const char, double) override;
  virtual void move(double, double) override;
  virtual void scale(double) override;
private:
  Point_t pointLl = { 0, 0 };
  Point_t pointUr = { 0, 0 };
  double width_ = 0;
  double height_ = 0;
  Point_t pos_ = { 0, 0 };
};

#endif
