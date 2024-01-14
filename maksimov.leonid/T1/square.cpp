#include "square.hpp"

Square::Square(float x, float y, float width) :
  pointLl{ x, y },
  pointUr{ x + width, x + width },
  width_{width},
  height_{width}
{
  Point_t pos_{ width_ / 2, height_ / 2 };
}
float Square::getArea()
{
  return width_ * height_;
}
Rectangle_t Square::getFrameRect()
{
  return { width_, height_, pos_ };
}
void Square::move(const char axis, float n)
{
  if (axis == 'x')
  {
    pointLl.x += n;
    pointUr.x += n;
    pos_.x += n;
  }
  else if (axis == 'y')
  {
    pointLl.y += n;
    pointUr.y += n;
    pos_.y += n;
  }
}
void Square::move(float x, float y)
{
  pointLl = { x - width_, y - height_ };
  pointUr = { x + width_, y + height_ };
  pos_ = { x, y };
}
void Square::scale(float k)
{
  width_ *= k;
  height_ *= k;
}
