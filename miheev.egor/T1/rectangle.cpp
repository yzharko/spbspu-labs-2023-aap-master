#include "rectangle.hpp"
#include <cmath>

miheev::Rectangle::Rectangle(point_t* points):
  width_(-1),
  height_(-1)
{
  double diag = 0;
  points_[0] = points[0]; // base point
  size_t nonDiag[2] = {0};
  size_t indexNonDiag = 0;
  for (size_t i = 1; i < 4; i++)
  {
    double dist = points_[0].distTo(points[i]);
    if (dist > diag)
    {
      diag = dist;
      points_[2] = points[i]; // temporary diag diagonal to base
    }
    else
    {
      nonDiag[indexNonDiag] = i;
      indexNonDiag++;
    }
  } // 0 -> 2 is diagonal

  points_[1] = points[nonDiag[0]];
  points_[3] = points[nonDiag[1]]; // 1 -> 3 is diagonal
  // I suppose it's rectangle without validating
  width_ = points_[0].distTo(points_[1]);
  height_ = points_[1].distTo(points_[2]);
}

double miheev::Rectangle::getArea() const
{
  return width_*height_;
}

miheev::rectangle_t miheev::Rectangle::getFrameRect() const
{
  point_t top = points_[0];
  point_t bottom = points_[0];
  point_t left = points_[0];
  point_t right = points_[0];
  for (size_t i = 0; i < 4; i++)
  {
    point_t cur = points_[i];
    if (cur.y_ > top.y_)
    {
      top = cur;
    }
    if(cur.y_ < bottom.y_)
    {
      bottom = cur;
    }
    if (cur.x_ > right.x_)
    {
      right = cur;
    }
    if (cur.x_ < left.x_)
    {
      left = cur;
    }
  }

  double width = left.distTo(right);
  double height = top.distTo(bottom);
  point_t center(left.x_ + width/2, bottom.y_ + height/2);
  return rectangle_t(center, width, height);
}

void miheev::Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 4; i++)
  {
    points_[i].x_ += dx;
    points_[i].y_ += dy;
  }
}