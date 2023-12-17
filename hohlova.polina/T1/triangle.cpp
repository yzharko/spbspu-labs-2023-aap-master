#include "triangle.hpp"
#include <cmath>
#include <stdexcept>

hohlova::Triangle::Triangle(point_t pos1, point_t pos2, point_t pos3)
{
  double a = sqrt((pos2_.x - pos1_.x)*(pos2_.x - pos1_.x) - (pos2_.y - pos1_.y)*(pos2_.y - pos1_.y));
  double b = sqrt((pos3_.x - pos1_.x)*(pos3_.x - pos1_.x) - (pos3_.y - pos1_.y)*(pos3_.y - pos1_.y));
  double c = sqrt((pos3_.x - pos2_.x)*(pos3_.x - pos2_.x) - (pos3_.y - pos2_.y)*(pos3_.y - pos2_.y));
}
double hohlova::Triangle::getArea()
{
  return 0.5 * abs((pos2_.x - pos1_.x) * (pos3_.y - pos1_.y) - (pos3_.x - pos1_.x) * (pos2_.y - pos1_.y));
}
rectangle_t hohlova::Triangle::getFrameRect()
{
  double maxX = std::max(std::max(pos1_.x, pos2_.x), pos3_.x);
  double minX = std::min(std::min(pos1_.x, pos2_.x), pos3_.x);
  double width_ = maxX - minX;
  double maxY = std::max(std::max(pos1_.y, pos2_.y), pos3_.y);
  double minY = std::min(std::min(pos1_.y, pos2_.y), pos3_.y);
  double height_ = maxY - minY;
  return { width_, height_, pos_ };
  return rectangle_t();
}
void hohlova::Triangle::move(point_t p)
{
  pos_.x = p.x;
  pos_.y = p.y;
}
void hohlova::Triangle::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}
void hohlova::Triangle::scale(double k)
{
  a_ *= k;
  b_ *= k;
  c_ *= k;
}
