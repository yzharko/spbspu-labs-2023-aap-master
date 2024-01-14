#include "rectangle.hpp"

Rectangle::Rectangle(double x1, double y1, double x2, double y2) :
  pointLl{ x1, y1 },
  pointUr{ x2, y2 }
{
  width_ = abs(pointUr.x) + abs(pointLl.x);
  height_ = abs(pointUr.y) + abs(pointLl.y);
  this->pos_ = { (abs(pointUr.x) - abs(pointLl.x)) / 2, (abs(pointUr.y) - abs(pointLl.y)) / 2 };
}

double Rectangle::getArea()
{
  return width_ * height_;
}

Rectangle_t Rectangle::getFrameRect()
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const char axis, double n)
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

void Rectangle::move(double x, double y)
{
  pointLl = { x -  width_, y - height_ };
  pointUr = { x + width_, y + height_ };
  pos_ = { x, y };
}

void Rectangle::scale(double k)
{
  width_ *= k;
  height_ *= k;
}
