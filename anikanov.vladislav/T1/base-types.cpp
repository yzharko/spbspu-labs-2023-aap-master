#include "base-types.h"
#include <iostream>
#include <iomanip>

PointT::PointT()
{
  x = 0;
  y = 0;
}

PointT::PointT(double x, double y)
{
  this->x = x;
  this->y = y;
}

PointT::PointT(const PointT &other)
{
  x = other.x;
  y = other.y;
}

PointT &PointT::operator=(const PointT another_point)
{
  if (this == &another_point) {
    return *this;
  }
  this->x = another_point.x;
  this->y = another_point.y;
  return *this;
}

std::ostream &operator<<(std::ostream &out, const PointT &point)
{
  out << std::fixed << std::setprecision(5);
  out << point.x << " " << point.y;
  return out;
}

std::istream &operator>>(std::istream &in, PointT &point)
{
  if (!(in >> point.x >> point.y)){
    if (std::cin.eof()){
      throw std::logic_error("EOF");
    }
    throw std::overflow_error("Invalid Input");
  }
  return in;
}

PointT &PointT::operator+(PointT another_point)
{
  x += another_point.x;
  y += another_point.y;
  return *this;
}

RectangleT::RectangleT()
{
  this->pos = PointT(0, 0);
  this->width = 0;
  this->height = 0;
}

RectangleT::RectangleT(PointT pos, double width, double height)
{
  this->pos = pos;
  this->width = width;
  this->height = height;
}

std::ostream &operator<<(std::ostream &out, const RectangleT &rec)
{
  out << PointT(rec.pos.x - rec.width / 2, rec.pos.y - rec.height / 2);
  out << " ";
  out << PointT(rec.pos.x + rec.width / 2, rec.pos.y + rec.height / 2);
  out << "\n";
  return out;
}
