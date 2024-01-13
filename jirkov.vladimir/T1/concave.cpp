#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>
using namespace jirkov;
Concave::Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourthPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint),
  fourthPoint_(fourthPoint)
{}

double Concave::getArea() const {
  double x1 = firstPoint_.x;
  double y1 = firstPoint_.y;
  double x2 = secondPoint_.x;
  double y2 = secondPoint_.y;
  double x3 = thirdPoint_.x;
  double y3 = thirdPoint_.y;
  double x4 = fourthPoint_.x;
  double y4 = fourthPoint_.y;

  double firstArea = (x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2));
  firstArea = std::abs(firstArea / 2.0);

  double secondArea = (x4 * (y2 - y3)) + (x2 * (y3 - y4)) + (x3 * (y4 - y2));
  secondArea = std::abs(secondArea / 2.0);

  return firstArea - secondArea;
}
rectangle_t Concave::getFrameRect() const
{
  double maxX = std::max({ firstPoint_.x, secondPoint_.x, thirdPoint_.x });
  double minX = std::min({ firstPoint_.x, secondPoint_.x, thirdPoint_.x });
  double maxY = std::max({ firstPoint_.y, secondPoint_.y, thirdPoint_.y });
  double minY = std::min({ firstPoint_.y, secondPoint_.y, thirdPoint_.y });
  double width = maxX - minX;
  double height = maxY - minY;
  double posX = (minX + width) * 0.5;
  double posY = (minY + height) * 0.5;
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}

void Concave::move(const point_t & destination)
{
  double moveX = destination.x - fourthPoint_.x;
  double moveY = destination.y - fourthPoint_.y;
  move(moveX, moveY);
  firstPoint_.x += moveX;
  firstPoint_.y += moveY;
  secondPoint_.x += moveX;
  secondPoint_.y += moveY;
  thirdPoint_.x += moveX;
  thirdPoint_.y += moveY;
  fourthPoint_.x += moveX;
  fourthPoint_.y += moveY;

}

void Concave::move(double moveX, double moveY)
{
  firstPoint_.x += moveX;
  firstPoint_.y += moveY;
  secondPoint_.x += moveX;
  secondPoint_.y += moveY;
  thirdPoint_.x += moveX;
  thirdPoint_.y += moveY;
  fourthPoint_.x += moveX;
  fourthPoint_.y += moveY;
}

void Concave::scale(double k)
{
  point_t pos = fourthPoint_;

  firstPoint_.x = pos.x + (firstPoint_.x - pos.x) * k;
  firstPoint_.y = pos.y + (firstPoint_.y - pos.y) * k;
  secondPoint_.x = pos.x + (secondPoint_.x - pos.x) * k;
  secondPoint_.y = pos.y + (secondPoint_.y - pos.y) * k;
  thirdPoint_.x = pos.x + (thirdPoint_.x - pos.x) * k;
  thirdPoint_.y = pos.y + (thirdPoint_.y - pos.y) * k;
}
