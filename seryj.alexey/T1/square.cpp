#include "square.hpp"
#include <exception>
#include <iostream>
using namespace seryj;
Square::Square(point_t pos, double side)
{
  if (side <= 0)
    throw std::logic_error("Square side cant be negative\n");
  point_ = pos;
  side_ = side;
}
double Square::getArea()const
{
  return side_ * side_;
}
rectangle_t Square::getFrameRect()const
{
  return rectangle_t{ side_, side_, {point_.x + side_ / 2, point_.y + side_ / 2} };
}
void Square::move(point_t p)
{
  point_.x = p.x - side_ / 2;
  point_.y = p.y - side_ / 2;
}
void Square::move(double x, double y)
{
  point_.x += x;
  point_.y += y;
}
void Square::scale(double k)
{
  double old_side = side_;
  side_ *= k;
  point_.x -= (side_ - old_side) / 2;
  point_.y -= (side_ - old_side) / 2;
}
