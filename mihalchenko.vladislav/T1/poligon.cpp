#include "poligon.hpp"
#include <cmath>

using namespace mihalchenko;

Poligon::Poligon()
{

}

double mihalchenko::Poligon::getArea() const
{
  return {rectangle_.width_ * rectangle_.height_};
}

rectangle_t mihalchenko::Poligon::getFrameRect() const
{
  return {0, 0, {0, 0}};
}

void Poligon::move(const point_t &point)
{
  rectangle_.pos_ = point;
}

void Poligon::move(const double deltaX, const double deltaY)
{

}

void Poligon::scale(double scaleKoef)
{
  rectangle_.height_ = scaleKoef * rectangle_.height_;
  rectangle_.width_ = scaleKoef * rectangle_.width_;
}
