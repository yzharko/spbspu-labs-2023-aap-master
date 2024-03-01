#include "base-types.hpp"

yartsev::point_t::point_t():
  x_(0),
  y_(0)
{}

yartsev::point_t::point_t(double x, double y):
  x_(x),
  y_(y)
{}

double yartsev::rectangle_t::getArea()
{
  return width_ * height_;
}

yartsev::point_t yartsev::rectangle_t::getLowerPoint()
{
  point_t rez(pos_.x_ - width_ / 2.0, pos_.y_ - height_ / 2.0);
  return rez;
}

yartsev::point_t yartsev::rectangle_t::getTopPoint()
{
  point_t rez(pos_.x_ + width_ / 2.0, pos_.y_ + height_ / 2.0);
  return rez;
}

yartsev::rectangle_t::rectangle_t():
  width_(0),
  height_(0),
  pos_()
{}

yartsev::rectangle_t::rectangle_t(double width, double height, point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{}
