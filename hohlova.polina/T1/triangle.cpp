#include "triangle.hpp"
#include <cmath>
#include <stdexcept>

hohlova::Triangle::Triangle(point_t pos1, point_t pos2, point_t pos3) :
  pos1_(pos1),
  pos2_(pos2),
  pos3_(pos3)
{}
double hohlova::Triangle::getArea()
{
  double a = sqrt(pow((pos1_.x_ - pos2_.x_), 2) + pow((pos1_.y_ - pos2_.y_), 2));
  double b = sqrt(pow((pos2_.x_ - pos3_.x_), 2) + pow((pos2_.y_ - pos3_.y_), 2));
  double c = sqrt(pow((pos3_.x_ - pos1_.x_), 2) + pow((pos3_.y_ - pos1_.y_), 2));
  double halfPer = 0.5 * (a + b + c);
  return sqrt(halfPer * (halfPer - a) * (halfPer - b) * (halfPer - c));
}
rectangle_t hohlova::Triangle::getFrameRect()
{
  double maxX = std::max(std::max(pos1_.x_, pos2_.x_), pos3_.x_);
  double minX = std::min(std::min(pos1_.x_, pos2_.x_), pos3_.x_);
  double width_ = maxX - minX;
  double maxY = std::max(std::max(pos1_.y_, pos2_.y_), pos3_.y_);
  double minY = std::min(std::min(pos1_.y_, pos2_.y_), pos3_.y_);
  double height_ = maxY - minY;
  point_t pos = { 0.5 * (maxX - minX), 0.5 * (maxY - minY) };
  return rectangle_t {width_, height_, pos};
}
void hohlova::Triangle::move(point_t p)
{
  double replaceX = p.x_ - (pos1_.x_ + pos2_.x_ + pos3_.x_) / 3;
  double replaceY = p.y_ - (pos1_.y_ + pos2_.y_ + pos3_.y_) / 3;
  pos1_.x_ += replaceX;
  pos2_.x_ += replaceX;
  pos3_.x_ += replaceX;
  pos1_.y_ += replaceY;
  pos2_.y_ += replaceY;
  pos3_.y_ += replaceY;
}
void hohlova::Triangle::move(double x, double y)
{
  pos1_.x_ += x;
  pos2_.x_ += x;
  pos3_.x_ += x;
  pos1_.y_ += y;
  pos2_.y_ += y;
  pos3_.y_ += y;
}
void hohlova::Triangle::scale(double k)
{
  pos1_.x_ *= k;
  pos2_.x_ *= k;
  pos3_.x_ *= k;
  pos1_.y_ *= k;
  pos2_.y_ *= k;
  pos3_.y_ *= k;
}
