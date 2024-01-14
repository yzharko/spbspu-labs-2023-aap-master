#include "base-types.hpp"
#include <iostream>

likhachev::point_t::point_t(double newX, double newY):
  x(newX),
  y(newY)
{}

likhachev::point_t likhachev::point_t::operator+(const point_t& rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

likhachev::point_t likhachev::point_t::operator-(const point_t& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

bool likhachev::point_t::operator==(const point_t& rhs)
{
  if (x == rhs.x && y == rhs.y) {
    return true;
  }

  return false;
}

likhachev::point_t& likhachev::point_t::operator+=(const point_t& rhs)
{
  *this = *this + rhs;
  return *this;
}

likhachev::point_t& likhachev::point_t::operator-=(const point_t& rhs)
{
  *this = *this - rhs;
  return *this;
}

likhachev::rectangle_t::rectangle_t(double newWidth, double newHeight, likhachev::point_t newPos):
  width(newWidth),
  height(newHeight),
  pos(newPos)
{}

double likhachev::rectangle_t::getArea() const
{
  return width * height;
}

double likhachev::rectangle_t::getWidth() const
{
  return width;
}

double likhachev::rectangle_t::getHeight() const
{
  return height;
}

likhachev::point_t likhachev::rectangle_t::getPos() const
{
  return pos;
}

void likhachev::rectangle_t::setWidth(double newWidth)
{
  if (width <= 0) {
    throw std::logic_error("Error: the width of the figure cannot be non-positive\n");
  }
  width = newWidth;
}

void likhachev::rectangle_t::setHeight(double newHeight)
{
  if (height <= 0) {
    throw std::logic_error("Error: the height of the figure cannot be non-positive\n");
  }
  height = newHeight;
}

void likhachev::rectangle_t::setPos(likhachev::point_t newPos)
{
  pos = newPos;
}
