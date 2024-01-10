#include "rectangle.hpp"
#include <iostream>

using namespace anikanov;

Rectangle::Rectangle()
{
  width = 0;
  height = 0;
  cPoint = PointT();
}

void Rectangle::setWidth(float newWidth)
{
  width = newWidth;
}

float Rectangle::getWidth() const
{
  return width;
}

void Rectangle::setHeight(float newHeight)
{
  height = newHeight;
}

float Rectangle::getHeight() const
{
  return height;
}

PointT Rectangle::getCPoint() const
{
  return cPoint;
}

long long Rectangle::getArea()
{
  return width * height;
}

RectangleT Rectangle::getFrameRect()
{
  return RectangleT(cPoint, width, height);
}

void Rectangle::move(PointT newCPoint)
{
  cPoint = newCPoint;
}

void Rectangle::move(float x, float y)
{
  cPoint = PointT(x, y);
}

void Rectangle::scale(float k)
{
  if (k < 0){
    throw std::logic_error("Invalid scale argument");
  }
  width *= 2;
  height *= 2;
}

std::istream &operator>>(std::istream &in, Rectangle &rec)
{
  PointT leftBottom, rightTop;
  if (!(in >> leftBottom >> rightTop)){
    throw std::overflow_error("Invalid Input Rectangle");
  }
  if (rightTop.x <= leftBottom.x || rightTop.y <= leftBottom.y) {
    throw std::overflow_error("Invalid Input Rectangle");
  }
  rec.width = rightTop.x - leftBottom.x;
  rec.height = rightTop.y - leftBottom.y;
  rec.cPoint = PointT(leftBottom.x + rec.width / 2,
                      leftBottom.y + rec.height / 2);
  return in;
}
