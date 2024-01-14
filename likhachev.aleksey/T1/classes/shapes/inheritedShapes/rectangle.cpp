#include "rectangle.hpp"
#include <iostream>

likhachev::Rectangle::Rectangle(likhachev::Point_t lowerLeft, likhachev::Point_t upperRight):
  lowerLeft_(lowerLeft),
  upperRight_(upperRight)
{
  if (lowerLeft_.x >= upperRight_.x || lowerLeft_.y >= upperRight_.y) {
    throw std::logic_error("The parameters are not logically incorrect\n");
  }
}

likhachev::Rectangle::Rectangle(double lowerLeftX, double lowerLeftY, double upperRightX, double upperRightY):
  lowerLeft_(likhachev::Point_t(lowerLeftX, lowerLeftY)),
  upperRight_(likhachev::Point_t(upperRightX, upperRightY))
{
  if (lowerLeft_.x >= upperRight_.x || lowerLeft_.y >= upperRight_.y) {
    throw std::logic_error("The parameters are not logically incorrect\n");
  }
}

double likhachev::Rectangle::getArea() const
{
  return getWidth() * getHeight();
}

likhachev::Rectangle_t likhachev::Rectangle::getFrameRect() const
{
  double width = getWidth();
  double height = getHeight();
  likhachev::Point_t pos = getPos();

  return Rectangle_t(width, height, pos);
}

void likhachev::Rectangle::move(likhachev::Point_t offset)
{
  likhachev::Point_t pos = getPos();
  move(offset.x - pos.x, offset.y - pos.y);
}

void likhachev::Rectangle::move(double offsetX, double offsetY)
{
  likhachev::Point_t offset(offsetX, offsetY);
  upperRight_ += offset;
  lowerLeft_ += offset;
}

void likhachev::Rectangle::scale(double multiplier)
{
  double width = getWidth();
  double height = getHeight();
  likhachev::Point_t offset(((multiplier * width) - width) / 2, ((multiplier * height) - height) / 2);

  upperRight_ += offset;
  lowerLeft_ -= offset;
}

likhachev::Point_t likhachev::Rectangle::getPos() const
{
  likhachev::Point_t pos((upperRight_.x + lowerLeft_.x) / 2, (upperRight_.y + lowerLeft_.y) / 2);
  return pos;
}

double likhachev::Rectangle::getWidth() const
{
  return upperRight_.x - lowerLeft_.x;
}

double likhachev::Rectangle::getHeight() const
{
  return upperRight_.y - lowerLeft_.y;
}
