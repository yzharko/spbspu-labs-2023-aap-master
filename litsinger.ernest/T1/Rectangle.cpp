#include"Rectangle.hpp"
Rectangle::Rectangle(double weight, double height, const point_t& pos)
{
}
double Rectangle::getArea() const {
  return framework.height * framework.width;
}
rectangle_t Rectangle::getFrameRect() const {
  return framework;
}
void Rectangle::move(double x, double y) {
  framework.pos.x += x;
  framework.pos.y += y;
}
void Rectangle::move(const point_t& point) {
  this->framework.pos = point;
}
void Rectangle::scale(double k) {
  if (k <= 0) {
    throw std::invalid_argument("incorrect k");
  }
  framework.height *= k;
  framework.width *= k;
}
std::ostream& operator << (std::ostream& os, const Rectangle& rectangle) {
  return os << rectangle.getFrameRect();
}
