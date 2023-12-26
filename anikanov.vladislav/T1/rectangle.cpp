#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle()
{
  width = 0;
  height = 0;
  cPoint = PointT();
}

void Rectangle::setWidth(double newWidth)
{
  width = newWidth;
}

double Rectangle::getWidth() const
{
  return width;
}

void Rectangle::setHeight(double newHeight)
{
  height = newHeight;
}

double Rectangle::getHeight() const
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

void Rectangle::move(double x, double y)
{
  cPoint = PointT(x, y);
}

void Rectangle::scale(double k)
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
  rec.cPoint = PointT(leftBottom.x + (rightTop.x - leftBottom.x) / 2,
                      leftBottom.y + (rightTop.y - leftBottom.y) / 2);
  rec.width = rightTop.x - leftBottom.x;
  rec.height = rightTop.y - leftBottom.y;
  return in;
}
