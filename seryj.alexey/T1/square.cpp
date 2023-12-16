#include "square.hpp"
Square::Square(point_t pos, double side)
{
  side_ = side;
  pos_.x = pos.x + side/2;
  pos_.y = pos.y + side/2;
}
double Square::getArea()
{
  return side_ * side_;
}
rectangle_t Square::getFrameRect()
{
  return rectangle_t{side_, side_, pos_};
}
void Square::move(point_t p)
{
  pos_ = p;
}
void Square::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}
void Square::scale(double k)
{
  side_ *= k;
}

