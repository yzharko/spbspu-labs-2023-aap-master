#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
using namespace maksimov;

class Square : public Shape
{
public:
  Square(double, double, double);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(const double&, const double&) override;
  virtual void move(const point_t&) override;
  virtual void scale(double) override;
private:
  point_t pointLl = { 0, 0 };
  point_t pointUr = { 0, 0 };
  double width_ = 0;
  double height_ = 0;
  point_t pos_ = { 0, 0 };
};

#endif
