#include "rectangle.cpp"

double Rectangle::getArea()
{
  return rectangle.width * rectangle.height;
}
rectangle_t Rectangle::getFrameRec()
{
  return *this;
}
void Rectangle::move(point_t p)
{
  rectangle.pos.x = p.x;
  rectangle.pos.y = p.y;
}
void Rectangle::move(double xPlus, double yPlus)
{
  rectangle.pos.x += xPlus;
  rectangle.pos.y += yPlus;
}
void Rectangle::scale(double multiplier)
{
  rectangle.width *= multiplier;
  rectangle.height *= multiplier;
  rectangle.pos.x *= multiplier;
  rectangle.pos.y *= multiplier;
}



