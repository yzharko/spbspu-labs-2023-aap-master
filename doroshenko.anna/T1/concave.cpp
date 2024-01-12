#include "concave.hpp"
#include <cmath>
#include <stdexcept>

using namespace doroshenko;

Concave::Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourthPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint),
  fourthPoint_(fourthPoint)
{}

double Concave::getArea() const
{
  double aF = sqrt(pow((firstPoint_.x - secondPoint_.x), 2) + pow((firstPoint_.y - secondPoint_.y), 2));
  double bF = sqrt(pow((secondPoint_.x - thirdPoint_.x), 2) + pow((secondPoint_.y - thirdPoint_.y), 2));
  double cF = sqrt(pow((thirdPoint_.x - firstPoint_.x), 2) + pow((thirdPoint_.y - firstPoint_.y), 2));
  double pF = 0.5 * (aF + bF + cF);
  double firstArea = sqrt(pF * (pF - aF) * (pF - bF) * (pF - cF));

  double maxSide = aF >= bF ? aF : bF;
  maxSide = maxSide >= cF ? maxSide : cF;
  if (maxSide >= aF + bF + cF - maxSide)
  {
    throw std::logic_error("There is no such triangle\n");
  }

  double aS = sqrt(pow((fourthPoint_.x - secondPoint_.x), 2) + pow((fourthPoint_.y - secondPoint_.y), 2));
  double bS = sqrt(pow((secondPoint_.x - thirdPoint_.x), 2) + pow((secondPoint_.y - thirdPoint_.y), 2));
  double cS = sqrt(pow((thirdPoint_.x - fourthPoint_.x), 2) + pow((thirdPoint_.y - fourthPoint_.y), 2));
  double pS = 0.5 * (aS + bS + cS);
  double secondArea = sqrt(pS * (pS - aS) * (pS - bS) * (pS - cS));

  maxSide = aS >= bS ? aS : bS;
  maxSide = maxSide >= cS ? maxSide : cS;
  if (maxSide >= aS + bS + cS - maxSide)
  {
    throw std::logic_error("There is no such triangle\n");
  }

  double a = sqrt(pow((firstPoint_.x - secondPoint_.x), 2) + pow((firstPoint_.y - secondPoint_.y), 2));
  double b = sqrt(pow((secondPoint_.x - fourthPoint_.x), 2) + pow((secondPoint_.y - fourthPoint_.y), 2));
  double c = sqrt(pow((fourthPoint_.x - firstPoint_.x), 2) + pow((fourthPoint_.y - firstPoint_.y), 2));

  maxSide = a >= b ? a : b;
  maxSide = maxSide >= c ? maxSide : c;
  if (maxSide >= a + b + c - maxSide)
  {
    throw std::logic_error("There is no such triangle\n");
  }

  a = sqrt(pow((firstPoint_.x - thirdPoint_.x), 2) + pow((firstPoint_.y - thirdPoint_.y), 2));
  b = sqrt(pow((thirdPoint_.x - fourthPoint_.x), 2) + pow((thirdPoint_.y - fourthPoint_.y), 2));
  c = sqrt(pow((fourthPoint_.x - firstPoint_.x), 2) + pow((fourthPoint_.y - firstPoint_.y), 2));

  maxSide = a >= b ? a : b;
  maxSide = maxSide >= c ? maxSide : c;
  if (maxSide >= a + b + c - maxSide)
  {
    throw std::logic_error("There is no such triangle\n");
  }
  return firstArea - secondArea;
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
  double posX = 0.5 * (maxX + minX);
  double posY = 0.5 * (maxY + minY);
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}

void Concave::move(point_t destination)
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

void Concave::scale(double coefficient)
{
  point_t pos;
  pos.x = fourthPoint_.x;
  pos.y = fourthPoint_.y;
  firstPoint_.x += (firstPoint_.x - pos.x) * (coefficient - 1);
  firstPoint_.y += (firstPoint_.y - pos.y) * (coefficient - 1);
  secondPoint_.x += (secondPoint_.x - pos.x) * (coefficient - 1);
  secondPoint_.y += (secondPoint_.y - pos.y) * (coefficient - 1);
  thirdPoint_.x += (thirdPoint_.x - pos.x) * (coefficient - 1);
  thirdPoint_.y += (thirdPoint_.y - pos.y) * (coefficient - 1);
}
