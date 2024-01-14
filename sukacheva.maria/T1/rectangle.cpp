#include "rectangle.hpp"
#include <iostream>

sukacheva::Rectangle::Rectangle(point_t rightPoint, point_t leftPoint):
  rectangle({ std::abs(rightPoint.x - leftPoint.x), std::abs(rightPoint.y - leftPoint.y),
    { ((rightPoint.x + leftPoint.x) / 2), ((rightPoint.y + leftPoint.y) / 2) } })
{
  if ((leftPoint.x > rightPoint.x) || (leftPoint.y > rightPoint.y))
  {
    throw std::logic_error("wrong parameters\n");
  }
}

double sukacheva::Rectangle::getArea() const {
  return rectangle.height * rectangle.width;
}

sukacheva::rectangle_t sukacheva::Rectangle::getFrameRect() const {
  double width = rectangle.width;
  double height = rectangle.height;
  point_t pos = rectangle.pos;
  rectangle_t FrameRect = { width, height, pos };
  return FrameRect;
}

void sukacheva::Rectangle::move(const double& x, const double& y) {
  rectangle.pos = { rectangle.pos.x + x, rectangle.pos.y + y };
}

void sukacheva::Rectangle::move(const point_t& center) {
  rectangle.pos = center;
}

void sukacheva::Rectangle::scale(double k) {
  if (k <= 0) {
    throw std::logic_error("Incorrect scaling factor\n");
  }
  else {
    rectangle.width = rectangle.width * k;
    rectangle.height = rectangle.height * k;
  }
}
