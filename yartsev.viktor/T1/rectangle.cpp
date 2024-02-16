#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#include "rectangle.hpp"

double yartsev::Rectangle::getArea() const
{
  return rectangle.width_ * rectangle.height_;
}

yartsev::rectangle_t yartsev::Rectangle::getFrameRect()
{
  return rectangle;
}

void yartsev::Rectangle::move(const point_t & to) 
{
  rectangle.pos_ = to;
}

#endif
