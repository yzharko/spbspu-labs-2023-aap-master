#include "rectangle.hpp"
#include "base-types.hpp"
#include <iostream>

sukacheva::Rectangle::Rectangle(point_t rp, point_t lp) :
  right_point(rp),
  left_point(lp)
{
  if ((left_point.x_ > right_point.x_) || (left_point.y_ > right_point.y_))
  {
    throw std::logic_error("wrong parameters\n");
  }
}

double sukacheva::Rectangle::getArea() const {
  double first_side = std::abs(right_point.x_ - left_point.x_);
  double second_side = std::abs(right_point.y_ - left_point.y_);
  return first_side * second_side;
}

void sukacheva::Rectangle::move(double x, double y) {
  right_point = point_t(right_point.x_ + x, right_point.y_ + y);
  left_point = point_t(left_point.x_ + x, left_point.y_ + y);
}

void sukacheva::Rectangle::move(point_t center) {
  double newX = center.x_;
  double newY = center.y_;
  double oldX = (right_point.x_ + left_point.x_) / 2;
  double oldY = (right_point.y_ + left_point.y_) / 2;
  double dX = newX - oldX;
  double dY = newY - oldY;
  move(dX, dY);
}

void sukacheva::Rectangle::scale(double k) {
  double center_x = (right_point.x_ + left_point.x_) / 2;
  double center_y = (right_point.y_ + left_point.y_) / 2;
  double width = std::abs(right_point.x_ - left_point.x_);
  double height = std::abs(right_point.y_ - left_point.y_);

  double newWidth = width * k;
  double newHeight = height * k;
  right_point.x_ = center_x - newWidth / 2;
  right_point.y_ = center_y - newHeight / 2;
  left_point.x_ = center_x + newWidth / 2;
  left_point.y_ = center_y + newHeight / 2;
}


void sukacheva::Rectangle::newScale(point_t center, double k) {
  double xSideLeft = left_point.x_ - center.x_;
  double ySideLeft = left_point.y_ - center.y_;
  double xSideRight = right_point.x_ - center.x_;
  double ySideRight = right_point.y_ - center.y_;

  right_point.x_ = center.x_ + xSideRight * k;
  right_point.y_ = center.y_ + ySideRight * k;
  left_point.x_ = center.x_ + xSideLeft * k;
  left_point.y_ = center.y_ + ySideLeft * k;

}

sukacheva::rectangle_t sukacheva::Rectangle::getFrameRect() const {
  double width = std::abs(right_point.x_ - left_point.x_);
  double height = std::abs(right_point.y_ - left_point.y_);
  point_t pos(((right_point.x_ + left_point.x_) / 2), ((right_point.y_ + left_point.y_) / 2));
  rectangle_t FrameRect = rectangle_t(width, height, pos);
  return FrameRect;
}
