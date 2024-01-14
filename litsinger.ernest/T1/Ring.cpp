#include "Ring.hpp"
Ring::Ring(double xCenter, double yCenter, double outSideRadius, double innerRadius) :
  center{ xCenter,yCenter } {
  if (outSideRadius < innerRadius || outSideRadius <= 0) {
    throw std::invalid_argument("outside radious incorrect");
  }
  externalRadius = outSideRadius;
  if (innerRadius <= 0) {
    throw std::invalid_argument("inner radious incorrect");
  }
  this->innerRadius = innerRadius;
}
double Ring::getArea() const {
#define pi 3.14
  double square = pi * (externalRadius * externalRadius - innerRadius * innerRadius);
  return square;
}
base_types::rectangle_t Ring::getFrameRect() const {
  return base_types::rectangle_t{ 2 * externalRadius, 2 * externalRadius, center };
}
void Ring::move(double dx, double dy) {
  center.x += dx;
  center.y += dy;
}
void Ring::move(const base_types::point_t& point) {
  center = point;
}
void Ring::scale(double k) {
  if (k <= 0) {
    throw std::invalid_argument("incorrect k");
  }
  externalRadius *= k;
  innerRadius *= k;
}
double Ring::getExternalRadius() const {
  return externalRadius;
}
double Ring::getInnerRadius() const {
  return innerRadius;
}
const base_types::point_t& Ring::getCenter() const {
  return center;
}
std::ostream& operator<<(std::ostream& os, const Ring& ring) {
  return os << ring.getExternalRadius() << ring.getInnerRadius() << ring.getCenter();
}
