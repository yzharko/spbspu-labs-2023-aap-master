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
  double a = sqrt(pow((pos1_.x - pos2_.x), 2) + pow((pos1_.y - pos2_.y), 2));
  double b = sqrt(pow((pos2_.x - pos3_.x), 2) + pow((pos2_.y - pos3_.y), 2));
  double c = sqrt(pow((pos3_.x - pos1_.x), 2) + pow((pos3_.y - pos1_.y), 2));
  double halfPer = 0.5 * (a + b + c);
  return sqrt(halfPer * (halfPer - a) * (halfPer - b) * (halfPer - c));
}
rectangle_t hohlova::Triangle::getFrameRect()
{
  double maxX = std::max(std::max(pos1_.x, pos2_.x), pos3_.x);
  double minX = std::min(std::min(pos1_.x, pos2_.x), pos3_.x);
  double width_ = maxX - minX;
  double maxY = std::max(std::max(pos1_.y, pos2_.y), pos3_.y);
  double minY = std::min(std::min(pos1_.y, pos2_.y), pos3_.y);
  double height_ = maxY - minY;
  point_t pos = { 0.5 * (maxX - minX), 0.5 * (maxY - minY) };
  return rectangle_t {width_, height_, pos};
}
void hohlova::Triangle::move(point_t p)
{
  double replaceX = p.x - (pos1_.x + pos2_.x + pos3_.x) / 3;
  double replaceY = p.y - (pos1_.y + pos2_.y + pos3_.y) / 3;
  pos1_.x += replaceX;
  pos2_.x += replaceX;
  pos3_.x += replaceX;
  pos1_.y += replaceY;
  pos2_.y += replaceY;
  pos3_.y += replaceY;
}
void hohlova::Triangle::move(double x, double y)
{
  pos1_.x += x;
  pos2_.x += x;
  pos3_.x += x;
  pos1_.y += y;
  pos2_.y += y;
  pos3_.y += y;
}
void hohlova::Triangle::scale(double k)
{
  pos1_.x *= k;
  pos2_.x *= k;
  pos3_.x *= k;
  pos1_.y *= k;
  pos2_.y *= k;
  pos3_.y *= k;
}
