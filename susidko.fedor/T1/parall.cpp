#include "parall.hpp"
#include <iostream>
#include "base-types.hpp"

double Parallelogram::getArea()
{
  rectangle_t temp = getFrameRect();
  return temp.height * temp.wight;
}
point_t Parallelogram::getCenter()
{
  point_t po2 = this->po2_;
  point_t po3 = this->po3_;
  double wight = po3.x - po2.x;
  double height = po3.y - po2.y;
  point_t pos;
  pos.x = (po2.x + wight/2);
  pos.y = (po2.y + height/2);
  return pos;
}
/*point_t Rectangle::getP1()
{
  return this->po1_;
}
point_t Rectangle::getP2()
{
  return this->po2_;
}*/
rectangle_t Parallelogram::getFrameRect()
{
  point_t po1 = this->po1_;
  point_t po2 = this->po2_;
  point_t po3 = this->po3_;
  double wight = po2.x - 2 * po1.x + po3.x;
  double height = po2.y - 2 * po1.y + po3.y;
  point_t pos = (*this).getCenter();
  rectangle_t frame_rect;
  frame_rect.wight = wight;
  frame_rect.height = height;
  frame_rect.pos = pos;
  return frame_rect;
}
void Parallelogram::move(double x, double y)
{
  po1_.x += x;
  po1_.y += y;
  po2_.x += x;
  po2_.y += y;
  po3_.x += x;
  po3_.y += y;
}
void Parallelogram::move(point_t new_pos)
{
  point_t pos = getCenter();
  double x = new_pos.x - pos.x;
  double y = new_pos.y - pos.y;
  po1_.x += x;
  po1_.y += y;
  po2_.x += x;
  po2_.y += y;
  po3_.x += x;
  po3_.y += y;
}
rectangle_t Parallelogram::scale(double x, double y, double coef, rectangle_t frame)
{
  frame.pos.x = coef * frame.pos.x - (coef - 1) * x;
  frame.pos.y = coef * frame.pos.y - (coef - 1) * y;
  frame.height = coef * frame.height;
  frame.wight = coef * frame.wight;
  return frame;
}








