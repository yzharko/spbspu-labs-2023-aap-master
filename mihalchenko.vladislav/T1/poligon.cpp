#include "poligon.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace mihalchenko;

void sortingShell(double *arr, size_t num)
{
  /*for (double range = num / 2; range > 0; range /= 2)
  {
    for (size_t i = range; i < num; i += 1)
    {
      double temp = arr[i];
      size_t j;
      for (j = i; (j >= range) && (arr[j - range] > temp); j -= range)
      {
        arr[j] = arr[j - range];
      }
      arr[j] = temp;
    }
  }
  */
}

Poligon::Poligon(size_t count, point_t *points)
{
  counterOfPoints_ = count;
  arrayOfPoints_ = points;

  /* rectangle_.width_ = fabs(pos2_.x_ - pos1_.x_);
   rectangle_.height_ = fabs(pos2_.y_ - pos1_.y_);
   rectangle_.pos_.x_ = (pos2_.x_ + pos1_.x_) / 2;
   rectangle_.pos_.y_ = (pos2_.y_ + pos1_.y_) / 2;
   */
}

Poligon::~Poligon()
{
  delete[] arrayOfPoints_;
}

double mihalchenko::Poligon::getArea() const
{
  double area = 0;
  double *masX = new double[counterOfPoints_];
  double *masY = new double[counterOfPoints_];

  for (size_t i = 0; i < counterOfPoints_; i++)
  {
    masX[i] = arrayOfPoints_[i].x_;
    masY[i] = arrayOfPoints_[i].y_;
  }
  for (size_t i = 0; i < counterOfPoints_ - 1; i++)
  {
    area += masX[i] * masY[i + 1];
  }
  for (size_t i = 0; i < counterOfPoints_ - 1; i++)
  {
    area -= masY[i] * masX[i + 1];
  }
  area += (masX[counterOfPoints_ - 1] * masY[0] - masX[0] * masY[counterOfPoints_ - 1]);
  area *= 0.5;

  delete[] masX;
  delete[] masY;
  return {rectangle_.width_ * rectangle_.height_};
}
rectangle_t mihalchenko::Poligon::getFrameRect() const
{
  double *masX = new double[counterOfPoints_];
  double *masY = new double[counterOfPoints_];

  for (size_t i = 0; i < counterOfPoints_; i++)
  {
    masX[i] = arrayOfPoints_[i].x_;
    masY[i] = arrayOfPoints_[i].y_;
  }
  sortingShell(masX, counterOfPoints_);
  sortingShell(masY, counterOfPoints_);

  double minX = masX[0];
  double maxX = masX[counterOfPoints_];
  double minY = masY[0];
  double maxY = masY[counterOfPoints_];

  point_t LowerLeftCorner = {minX, minY};
  point_t lowerRoghtCorner = {maxX, maxY};

  delete[] masX;
  delete[] masY;

  // return {fabs(pos2_.x_ - pos1_.x_), fabs(pos2_.y_ - pos1_.y_), {(pos2_.x_ + pos1_.x_) / 2, (pos2_.y_ + pos1_.y_) / 2}};
  return {0, 0, {0, 0}};
}

void mihalchenko::Poligon::move(const point_t &point)
{
  // pos1_ = {pos1_.x_ + (point.x_ - rectangle_.pos_.x_), pos1_.y_ + (point.y_ - rectangle_.pos_.y_)};
  rectangle_.pos_ = point;
}

void mihalchenko::Poligon::move(const double deltaX, const double deltaY)
{
  // pos1_ = {pos1_.x_ + deltaX, pos1_.y_ + deltaY};
  rectangle_.pos_ = {rectangle_.pos_.x_ + deltaX, rectangle_.pos_.y_ + deltaY};
}

void mihalchenko::Poligon::scale(double scaleKoef)
{
  /*double deltaX = (1 - scaleKoef) * rectangle_.width_ / 2;
  double deltaY = (1 - scaleKoef) * rectangle_.height_ / 2;
  pos1_ = {pos1_.x_ + deltaX, pos1_.y_ + deltaY};
  deltaX = (scaleKoef - 1) * rectangle_.width_ / 2;
  deltaY = (scaleKoef - 1) * rectangle_.height_ / 2;
  pos2_ = {pos2_.x_ + deltaX, pos2_.y_ + deltaY};
  rectangle_.height_ = scaleKoef * rectangle_.height_;
  rectangle_.width_ = scaleKoef * rectangle_.width_;
  */
}
