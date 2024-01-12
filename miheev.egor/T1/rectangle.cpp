#include "rectangle.hpp"
#include <cmath>
#include <iostream>

miheev::Rectangle::Rectangle(miheev::point_t bottomLeft, miheev::point_t topRight)
{
  points_ = new point_t[4];
  points_[0] = point_t(bottomLeft.x, bottomLeft.y);
  points_[1] = point_t(bottomLeft.x, topRight.y);
  points_[2] = point_t(topRight.x, topRight.y);
  points_[3] = point_t(topRight.x, bottomLeft.y);
  center_ = bottomLeft.findMiddle(topRight);
  width_ = topRight.x - bottomLeft.x;
  height_ = topRight.y - bottomLeft.y;
}

miheev::Rectangle::~Rectangle()
{
  std::cout << "disruption\n";
  delete[] points_;
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
    points_[i].move(dx, dy);
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
