#include "Square.hpp"
Square::Square(double x, double y, double sideSize) :leftDown{ x,y } {
  if (sideSize <= 0) {
	throw std::invalid_argument("incorrect size of square");
  }
  this->sideSize = sideSize;
}
double Square::getArea() const {
  return sideSize * sideSize;
}
base_types::rectangle_t Square::getFrameRect() const {
  base_types::point_t center{ leftDown.x + sideSize / 2,leftDown.y + sideSize / 2 };
  return base_types::rectangle_t{ sideSize,sideSize,center };
}
void Square::move(double dx, double dy) {
  leftDown.x += dx;
  leftDown.y += dy;
}
void Square::move(const base_types::point_t& point) {
  leftDown = point;
}
void Square::scale(double k) {
  if (k <= 0) {
    throw std::invalid_argument("incorrect k");
  }
  sideSize *= k;
}
const base_types::point_t& Square::getLeftDown() const {
  return leftDown;
}
double Square::getSideSize() const {
  return sideSize;
}
std::ostream& operator<<(std::ostream& os, const Square& rectangle){
  return os << rectangle.getSideSize() <<  rectangle.getLeftDown();
}
