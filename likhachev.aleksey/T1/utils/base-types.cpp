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

likhachev::rectangle_t::rectangle_t(double width, double height, likhachev::point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{}

double likhachev::rectangle_t::getArea() const
{
  return width_ * height_;
}

double likhachev::rectangle_t::getWidth() const
{
  return width_;
}

double likhachev::rectangle_t::getHeight() const
{
  return height_;
}

likhachev::point_t likhachev::rectangle_t::getPos() const
{
  return pos_;
}

void likhachev::rectangle_t::setWidth(double width)
{
  if (width <= 0) {
    throw std::logic_error("Error: the width of the figure cannot be non-positive\n");
  }
  width_ = width;
}

void likhachev::rectangle_t::setHeight(double height)
{
  if (height <= 0) {
    throw std::logic_error("Error: the height of the figure cannot be non-positive\n");
  }
  height_ = height;
}

void likhachev::rectangle_t::setPos(point_t pos)
{
  pos_ = pos;
}
