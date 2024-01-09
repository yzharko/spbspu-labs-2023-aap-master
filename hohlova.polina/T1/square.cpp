#include "square.hpp"
hohlova::Square::Square(point_t pos, double side)
{
  side_ = side;
  pos_.x_ = pos.x_ + side / 2;
  pos_.y_ = pos.y_ + side / 2;
}
double hohlova::Square::getArea()
{
  return side_ * side_;
}
rectangle_t hohlova::Square::getFrameRect()
{
  return rectangle_t{ side_, side_, pos_ };
}
void hohlova::Square::move(point_t p)
{
  pos_ = p;
}
void hohlova::Square::move(double x, double y)
{
  pos_.x_ += x;
  pos_.y_ += y;
}
void hohlova::Square::scale(double k)
{
  side_ *= k;
}
