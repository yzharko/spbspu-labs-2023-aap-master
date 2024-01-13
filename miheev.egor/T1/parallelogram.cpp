#include "parallelogram.hpp"
#include <cmath>

miheev::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3)
{
  points_ = new point_t[4];
  points_[0] = p1;
  points_[1] = p2;
  points_[2] = p3;
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  points_[3] = point_t(p3.x - dx, p3.y - dy);
}

miheev::Parallelogram::~Parallelogram()
{
  delete[] points_;
}

double miheev::Parallelogram::getArea() const
{
  double ax = points_[1].x - points_[0].x;
  double ay = points_[1].y - points_[0].y;
  double bx = points_[3].x - points_[0].x;
  double by = points_[3].y - points_[0].y;
  return std::abs(ax * by - ay * bx);
}

miheev::rectangle_t miheev::Parallelogram::getFrameRect() const
{
  double top = points_[0].y;
  double bottom = points_[0].y;
  double left = points_[0].x;
  double right = points_[0].x;
  for (size_t i = 0; i < 4; i++)
  {
    point_t cur = points_[i];
    if (cur.y > top)
    {
      top = cur.y;
    }
    if(cur.y < bottom)
    {
      bottom = cur.y;
    }
    if (cur.x > right)
    {
      right = cur.x;
    }
    if (cur.x < left)
    {
      left = cur.x;
    }
  }

  double width = right - left;
  double height = top - bottom;
  point_t center(left + width/2, bottom + height/2);
  return rectangle_t(center, width, height);
}

void miheev::Parallelogram::move(double dx, double dy)
{
  for (size_t i = 0; i < 4; i++)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}

void miheev::Parallelogram::move(point_t p)
{
  double dx = p.x - center_.x;
  double dy = p.y - center_.y;
  move(dx, dy);
}

void miheev::Parallelogram::scale(double k)
{
  for (size_t i = 0; i < 4; i++)
  {
    double dx = (points_[i].x - center_.x) * (k - 1);
    double dy = (points_[i].y - center_.y) * (k - 1);
    points_[i].move(dx, dy);
  }
}
