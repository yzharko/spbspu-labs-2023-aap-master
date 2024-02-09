#include "rectangle.hpp"
#include <iostream>
#include "base-types.hpp"

double Rectangle::getArea()
{
  return ((po2_.x - po1_.x) * (po2_.y - po1_.y));
}
point_t Rectangle::getCenter()
{
  point_t po1 = this->po1_;
  point_t po2 = this->po2_;
  double wight = po2.x - po1.x;
  double height = po2.y - po1.y;
  point_t pos;
  pos.x = (po1.x + wight/2);
  pos.y = (po1.y + height/2);
  return pos;
}
point_t Rectangle::getP1()
{
  return this->po1_;
}
point_t Rectangle::getP2()
{
  return this->po2_;
}
rectangle_t Rectangle::getFrameRect()
{
  point_t po1 = this->po1_;
  point_t po2 = this->po2_;
  double wight = po2.x - po1.x;
  double height = po2.y - po1.y;
  //point_t pos;
  //pos.x = (po1.x + wight/2);
  //pos.y = (po1.y + height/2);
  point_t pos = (*this).getCenter();
  rectangle_t frame_rect;
  frame_rect.wight = wight;
  frame_rect.height = height;
  frame_rect.pos = pos;
  return frame_rect;
}
void Rectangle::move(double x, double y)
{
  po1_.x += x;
  po1_.y += y;
  po2_.x += x;
  po2_.y += y;
}
void Rectangle::move(point_t new_pos)
{
  point_t pos = getCenter();
  double x = new_pos.x - pos.x;
  double y = new_pos.y - pos.y;
  po1_.x += x;
  po1_.y += y;
  po2_.x += x;
  po2_.y += y;
}
rectangle_t Rectangle::scale(double x, double y, double coef, rectangle_t frame)
{
  frame.pos.x = coef * frame.pos.x - (coef - 1) * x;
  frame.pos.y = coef * frame.pos.y - (coef - 1) * y;
  frame.height = coef * frame.height;
  frame.wight = coef * frame.wight;
  return frame;
}
void Rectangle::print()
{
  std::cout << this->po1_.x << ' ' << this->po1_.y << '\n';
}








