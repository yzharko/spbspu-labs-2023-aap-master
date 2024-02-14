#include "polygon.hpp"
#include <iostream>
#include "base-types.hpp"

double Polygon::getArea()
{
  rectangle_t frame_rect = getFrameRect();
  return frame_rect.height * frame_rect.wight;
}
//point_t Rectangle::getCenter()
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
//point_t Rectangle::getP1()
{
  return this->po1_;
}
//point_t Rectangle::getP2()
{
  return this->po2_;
}
rectangle_t Polygon::getFrameRect()
{
  point_t min = point_t(10000000, 10000000);
  point_t max = point_t(-10000000, -10000000);
	for (point_t i : points_)
  {
    if (i.x < min.x)
    {
      min.x = i.x;
    }
    if (i.y < min.y)
    {
      min.y = i.y;
    }
    if (i.x > max.x)
    {
      max.x = i.x;
    }
    if (i.y > max.y)
    {
      max.y = i.y;
    }
  rectangle_t frame_rect;
  frame_rect.wight = max.x - min.x;
  frame_rect.height = max.y - min.y;
  frame_rect.pos = point_t(max.x - wight / 2, max.y - height / 2);
  return frame_rect;
}
//void Rectangle::move(double x, double y)
{
  po1_.x += x;
  po1_.y += y;
  po2_.x += x;
  po2_.y += y;
}
//void Rectangle::move(point_t new_pos)
{
  point_t pos = getCenter();
  double x = new_pos.x - pos.x;
  double y = new_pos.y - pos.y;
  po1_.x += x;
  po1_.y += y;
  po2_.x += x;
  po2_.y += y;
}
rectangle_t Polygon::scale(double x, double y, double coef, rectangle_t frame)
{
  frame.pos.x = coef * frame.pos.x - (coef - 1) * x;
  frame.pos.y = coef * frame.pos.y - (coef - 1) * y;
  frame.height = coef * frame.height;
  frame.wight = coef * frame.wight;
  return frame;
}









