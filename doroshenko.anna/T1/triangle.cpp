#include "triangle.hpp"
#include <cmath>
#include <stdexcept>

using namespace doroshenko;

Triangle::Triangle(point_t firstPoint, point_t secondPoint, point_t thirdPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{}

double Triangle::getArea() const
{
  double a = sqrt(pow((firstPoint_.x - secondPoint_.x), 2) + pow((firstPoint_.y - secondPoint_.y), 2));
  double b = sqrt(pow((secondPoint_.x - thirdPoint_.x), 2) + pow((secondPoint_.y - thirdPoint_.y), 2));
  double c = sqrt(pow((thirdPoint_.x - firstPoint_.x), 2) + pow((thirdPoint_.y - firstPoint_.y), 2));

  double maxSide = a >= b ? a : b;
  maxSide = maxSide >= c ? maxSide : c;

  if (maxSide >= a + b + c - maxSide)
  {
    throw std::logic_error("There is no such triangle\n");
  }

  double p = 0.5 * (a + b + c);
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

rectangle_t Triangle::getFrameRect() const
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
  double posX = 0.5 * (maxX + minX);
  double posY = 0.5 * (maxY + minY);
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}

void Triangle::move(const point_t& destination)
{
  double moveX = destination.x - (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3;
  double moveY = destination.y - (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3;
  move(moveX, moveY);
}

void Triangle::move(double moveX, double moveY)
{
  firstPoint_.x += moveX;
  firstPoint_.y += moveY;
  secondPoint_.x += moveX;
  secondPoint_.y += moveY;
  thirdPoint_.x += moveX;
  thirdPoint_.y += moveY;
}

void Triangle::scale(double coefficient)
{
  point_t pos;
  pos.x = (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3;
  pos.y = (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3;
  firstPoint_.x += (firstPoint_.x - pos.x) * (coefficient - 1);
  firstPoint_.y += (firstPoint_.y - pos.y) * (coefficient - 1);
  secondPoint_.x += (secondPoint_.x - pos.x) * (coefficient - 1);
  secondPoint_.y += (secondPoint_.y - pos.y) * (coefficient - 1);
  thirdPoint_.x += (thirdPoint_.x - pos.x) * (coefficient - 1);
  thirdPoint_.y += (thirdPoint_.y - pos.y) * (coefficient - 1);
}
