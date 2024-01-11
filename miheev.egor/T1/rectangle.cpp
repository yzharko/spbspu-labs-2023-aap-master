#include "rectangle.hpp"
#include <cmath>
#include <iostream>

miheev::Rectangle::Rectangle(point_t bottomLeft, point_t topRight):
{
  points[0] = bottomLeft;
  points[1] = point_t(bottomLeft.x, topRight.y);
  points[2] = topRight;
  points[3] = point_t(topRight.x, bottomLeft.y);
  center_ = bottomLeft.findMiddle(topRight);
  width_ = topRight.x - bottomLeft.x;
  height_ = topRight.y - bottomLeft.y;
}

double miheev::Rectangle::getArea() const
{
  return width_*height_;
}

miheev::rectangle_t miheev::Rectangle::getFrameRect() const
{
  return rectangle_t(center_, width_, height_);
}

void miheev::Rectangle::move(double dx, double dy)
{
  for(size_t i = 0; i < 4; i++)
  {
    points[i].move(dx, dy);
  }
  center_.move(dx, dy);
}

void miheev::Rectangle::move(point_t p)
{
  double dx = p.x - center_.x;
  double dy = p.y - center_.y;
  move(dx, dy);
}

void miheev::Rectangle::scale(double k)
{
  for (size_t i = 0; i < 4; i++)
  {
    double dx = points_[i].x - center_.x;
    double dy = points_[i].y - center_.y;
    points_[i].move(dx * k, dy * k);
  }
  width_*= k; //cheating a lil bit
  height_*=k;
}