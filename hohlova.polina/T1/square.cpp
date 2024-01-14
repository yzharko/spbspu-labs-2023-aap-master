#include "square.hpp"
hohlova::Square::Square(point_t pos, double side)
{
  side_ = side;
  pos.x = pos.x + side / 2;
  pos.y = pos.y + side / 2;
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
  pos_.x = p.x - side_ / 2;
  pos_.y = p.y - side_ / 2;
}
void hohlova::Square::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}
void hohlova::Square::scale(double k)
{
  double prevSide = side_;
  side_ *= k;
  double diff = side_ - prevSide;
  pos_.x -= diff;
  pos_.y -= diff;
}
