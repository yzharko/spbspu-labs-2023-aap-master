#include "rectangle.hpp"

Rectangle::Rectangle(float x1, float y1, float x2, float y2) :
  pointLl{ x1, y1 },
  pointUr{ x2, y2 }
{
  width_ = abs(pointUr.y - pointLl.y);
  height_ = abs(pointUr.x - pointLl.x);
  this->pos_ = { width_ / 2, height_ / 2 };
}

float Rectangle::getArea()
{
  return width_ * height_;
}

Rectangle_t Rectangle::getFrameRect()
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const char axis, float n)
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

void Rectangle::move(float x, float y)
{
  pointLl = { x -  width_, y - height_ };
  pointUr = { x + width_, y + height_ };
  pos_ = { x, y };
}

void Rectangle::scale(float k)
{
  width_ *= k;
  height_ *= k;
}
