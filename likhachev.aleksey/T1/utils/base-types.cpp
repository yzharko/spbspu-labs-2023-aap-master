#include "base-types.hpp"
#include <iostream>

likhachev::Point_t::Point_t(double newX, double newY):
  x(newX),
  y(newY)
{}

likhachev::Point_t likhachev::Point_t::operator+(const Point_t& rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

likhachev::Point_t likhachev::Point_t::operator-(const Point_t& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

bool likhachev::Point_t::operator==(const Point_t& rhs)
{
  if (x == rhs.x && y == rhs.y) {
    return true;
  }

  return false;
}

likhachev::Point_t& likhachev::Point_t::operator+=(const Point_t& rhs)
{
  *this = *this + rhs;
  return *this;
}

likhachev::Point_t& likhachev::Point_t::operator-=(const Point_t& rhs)
{
  *this = *this - rhs;
  return *this;
}

likhachev::Rectangle_t::Rectangle_t(double width, double height, likhachev::Point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{}

double likhachev::Rectangle_t::getArea() const
{
  return width_ * height_;
}

double likhachev::Rectangle_t::getWidth() const
{
  return width_;
}

double likhachev::Rectangle_t::getHeight() const
{
  return height_;
}

likhachev::Point_t likhachev::Rectangle_t::getPos() const
{
  return pos_;
}

void likhachev::Rectangle_t::setWidth(double width)
{
  if (width <= 0) {
    throw std::logic_error("Error: the width of the figure cannot be non-positive\n");
  }
  width_ = width;
}

void likhachev::Rectangle_t::setHeight(double height)
{
  if (height <= 0) {
    throw std::logic_error("Error: the height of the figure cannot be non-positive\n");
  }
  height_ = height;
}

void likhachev::Rectangle_t::setPos(Point_t pos)
{
  pos_ = pos;
}
