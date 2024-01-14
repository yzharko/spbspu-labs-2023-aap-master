#include "poligon.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace mihalchenko;

double square(double x1, double y1, double x2, double y2, double x3, double y3)
{
  return 0.5 * fabs((x2 - x3) * (y1 - y3) - (x1 - x3) * (y2 - y3));
}

Poligon::Poligon(size_t count, point_t *points) : counterOfPoints_(count),
                                                  arrayOfPoints_(points)
{
  double minX = std::numeric_limits<double>::max();
  double minY = std::numeric_limits<double>::max();
  double maxX = 0;
  double maxY = 0;

  for (size_t i = 0; i < counterOfPoints_; i++)
  {
    if (arrayOfPoints_[i].x_ > maxX)
    {
      maxX = arrayOfPoints_[i].x_;
    }
    if (arrayOfPoints_[i].y_ > maxY)
    {
      maxY = arrayOfPoints_[i].y_;
    }
    if (arrayOfPoints_[i].x_ < minX)
    {
      minX = arrayOfPoints_[i].x_;
    }
    if (arrayOfPoints_[i].y_ < minY)
    {
      minY = arrayOfPoints_[i].y_;
    }
  }
  rectangle_.height_ = maxY - minY;
  rectangle_.width_ = maxX - minX;

  double xc = 0.0, yc = 0.0;
  for (size_t i = 0; i < counterOfPoints_; i++)
  {
    double xm = 0.0, ym = 0.0;
    for (int i = 0; i < counterOfPoints_; i++)
    {
      xm += arrayOfPoints_[i].x_;
      ym += arrayOfPoints_[i].y_;
    }
    xm /= counterOfPoints_;
    ym /= counterOfPoints_;
    double s = 0.0;
    xc = 0.0;
    yc = 0.0;
    for (i = 0; i < counterOfPoints_; i++)
    {
      double s1 = square(xm, ym, arrayOfPoints_[i].x_, arrayOfPoints_[i].y_, arrayOfPoints_[(i + 1) % counterOfPoints_].x_, arrayOfPoints_[(i + 1) % counterOfPoints_].y_);
      xc += s1 * (xm + arrayOfPoints_[i].x_ + arrayOfPoints_[(i + 1) % counterOfPoints_].x_) / 3;
      yc += s1 * (ym + arrayOfPoints_[i].y_ + arrayOfPoints_[(i + 1) % counterOfPoints_].y_) / 3;
      s += s1;
    }
    xc /= s;
    yc /= s;
    rectangle_.pos_.x_ = xc;
    rectangle_.pos_.y_ = yc;
    pos1_.x_ = xc;
    pos1_.y_ = yc;
    width_ = rectangle_.width_;
    height_ = rectangle_.height_;

    pos1_.x_ = minX;
    pos1_.y_ = minY;
    pos2_.x_ = maxX;
    pos2_.y_ = maxY;
    pointCentre_.x_ = xc;
    pointCentre_.y_ = (pos2_.y_ + pos1_.y_) / yc;
  }
}

Poligon::~Poligon()
{
  delete[] arrayOfPoints_;
}

double mihalchenko::Poligon::getArea() const
{
  double area = width_ * height_;
  return area;
}
rectangle_t mihalchenko::Poligon::getFrameRect() const
{
  return {width_, height_, {pos1_.x_, pos1_.y_}};
}

void mihalchenko::Poligon::move(const point_t &point)
{
  for (int i = 0; i < counterOfPoints_; i++)
  {
    arrayOfPoints_[i].x_ = arrayOfPoints_[i].x_ + (point.x_ - pos1_.x_);
    arrayOfPoints_[i].y_ = arrayOfPoints_[i].y_ + (point.x_ - pos1_.x_);
    pos1_ = point;
    rectangle_.pos_ = point;
  }
}

void mihalchenko::Poligon::move(const double deltaX, const double deltaY)
{
  for (int i = 0; i < counterOfPoints_; i++)
  {
    arrayOfPoints_[i].x_ = arrayOfPoints_[i].x_ + deltaX;
    arrayOfPoints_[i].y_ = arrayOfPoints_[i].y_ + deltaY;
    pos1_.x_ = pos1_.x_ + deltaX;
    pos1_.y_ = pos1_.y_ + deltaY;
    rectangle_.pos_ = pos1_;
  }
}

void mihalchenko::Poligon::scale(double scaleKoef)
{
  for (int i = 0; i < counterOfPoints_; i++)
  {
    arrayOfPoints_[i].x_ = arrayOfPoints_[i].x_ - (pos1_.x_ - arrayOfPoints_[i].x_) * scaleKoef;
    arrayOfPoints_[i].y_ = arrayOfPoints_[i].y_ - (pos1_.x_ - arrayOfPoints_[i].x_) * scaleKoef;
  }
  rectangle_.height_ = rectangle_.height_ * scaleKoef;
  rectangle_.width_ = rectangle_.width_ * scaleKoef;
}
