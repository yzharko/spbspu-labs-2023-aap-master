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

void Rectangle::setCPoint(PointT newCPoint)
{
  cPoint = newCPoint;
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
  width *= 2;
  height *= 2;
}

std::istream &operator>>(std::istream &in, Rectangle &rec)
{
  PointT leftBottom, rightTop;
  in >> leftBottom >> rightTop;
  rec.cPoint = PointT((rightTop.x - leftBottom.x) / 2, (rightTop.y - leftBottom.y) / 2);
  rec.width = rightTop.x - leftBottom.x;
  rec.height = rightTop.y - leftBottom.y;
  return in;
}
