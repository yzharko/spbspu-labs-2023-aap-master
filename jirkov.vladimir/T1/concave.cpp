#include "concave.hpp"
#include <cmath>
#include <stdexcept>
using namespace jirkov;
Concave::Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourthPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint),
  fourthPoint_(fourthPoint)
{}

double Concave::getArea() const
{
  double x1 = firstPoint_.x;
  double y1 = firstPoint_.y;
  double x2 = secondPoint_.x;
  double y2 = secondPoint_.y;
  double x3 = thirdPoint_.x;
  double y3 = thirdPoint_.y;
  double x4 = fourthPoint_.x;
  double y4 = fourthPoint_.y;

  double firstArea = (x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)) / 2.0;
  double secondArea = (x4 * (y2 - y3)) + (x2 * (y3 - y4)) + (x3 * (y4 - y2)) / 2;
  return std::abs(firstArea - secondArea);
}
rectangle_t Concave::getFrameRect() const
{
  double maxX = firstPoint_.x >= secondPoint_.x ? firstPoint_.x : secondPoint_.x;
  maxX = maxX >= thirdPoint_.x ? maxX : thirdPoint_.x;
  double minX = firstPoint_.x <= secondPoint_.x ? firstPoint_.x : secondPoint_.x;
  minX = minX <= thirdPoint_.x ? minX : thirdPoint_.x;
  double maxY = firstPoint_.y >= secondPoint_.y ? firstPoint_.y : secondPoint_.y;
  maxY = maxY >= thirdPoint_.y ? maxY : thirdPoint_.y;
  double minY = firstPoint_.y <= secondPoint_.y ? firstPoint_.y : secondPoint_.y;
  minY = minY <= thirdPoint_.y ? minY : thirdPoint_.y;
  double width = maxX - minX;
  double height = maxY - minY;
  double posX = (maxX + minX) * 0.5;
  double posY = (maxY + minY) * 0.5;
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}

void Concave::move(const point_t & destination)
{
  double moveX = destination.x - fourthPoint_.x;
  double moveY = destination.y - fourthPoint_.y;
  move(moveX, moveY);
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
  point_t pos;
  pos.x = fourthPoint_.x;
  pos.y = fourthPoint_.y;
  firstPoint_.x += (firstPoint_.x - pos.x) * (k - 1);
  firstPoint_.y += (firstPoint_.y - pos.y) * (k - 1);
  secondPoint_.x += (secondPoint_.x - pos.x) * (k - 1);
  secondPoint_.y += (secondPoint_.y - pos.y) * (k - 1);
  thirdPoint_.x += (thirdPoint_.x - pos.x) * (k - 1);
  thirdPoint_.y += (thirdPoint_.y - pos.y) * (k - 1);
}
