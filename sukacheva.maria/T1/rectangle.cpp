#include "rectangle.hpp"
#include "base-types.hpp"
#include <iostream>

sukacheva::Rectangle::Rectangle(point_t rp, point_t lp) :
  right_point(rp),
  left_point(lp)
{
  if ((left_point.x > right_point.x) || (left_point.y > right_point.y))
  {
    throw std::logic_error("wrong parameters\n");
  }
}

double sukacheva::Rectangle::getArea() const {
  double first_side = std::abs(right_point.x - left_point.x);
  double second_side = std::abs(right_point.y - left_point.y);
  return first_side * second_side;
}

void sukacheva::Rectangle::move(double x, double y) {
  right_point = point_t(right_point.x + x, right_point.y + y);
  left_point = point_t(left_point.x + x, left_point.y + y);
}

void sukacheva::Rectangle::move(point_t center) {
  double newX = center.x;
  double newY = center.y;
  double oldX = (right_point.x + left_point.x) / 2;
  double oldY = (right_point.y + left_point.y) / 2;
  double dX = newX - oldX;
  double dY = newY - oldY;
  move(dX, dY);
}

void sukacheva::Rectangle::scale(double k) {
  double center_x = (right_point.x + left_point.x) / 2;
  double center_y = (right_point.y + left_point.y) / 2;
  double width = std::abs(right_point.x - left_point.x);
  double height = std::abs(right_point.y - left_point.y);

  double newWidth = width * k;
  double newHeight = height * k;
  right_point.x = center_x - newWidth / 2;
  right_point.y = center_y - newHeight / 2;
  left_point.x = center_x + newWidth / 2;
  left_point.y = center_y + newHeight / 2;
}


void sukacheva::Rectangle::newScale(point_t center, double k) {
  double xSideLeft = left_point.x - center.x;
  double ySideLeft = left_point.y - center.y;
  double xSideRight = right_point.x - center.x;
  double ySideRight = right_point.y - center.y;

  right_point.x = center.x + xSideRight * k;
  right_point.y = center.y + ySideRight * k;
  left_point.x = center.x + xSideLeft * k;
  left_point.y = center.y + ySideLeft * k;

}

sukacheva::rectangle_t sukacheva::Rectangle::getFrameRect() const {
  double width = std::abs(right_point.x - left_point.x);
  double height = std::abs(right_point.y - left_point.y);
  point_t pos(((right_point.x + left_point.x) / 2), ((right_point.y + left_point.y) / 2));
  rectangle_t FrameRect = rectangle_t(width, height, pos);
  return FrameRect;
}
