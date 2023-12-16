#include "rectangle.hpp"

likhachev::Rectangle::Rectangle(Point_t lowerLeft, Point_t upperRight):
  lowerLeft_(lowerLeft),
  upperRight_(upperRight)
{}

likhachev::Rectangle::Rectangle(double lowerLeftX, double lowerLeftY, double upperRightX, double upperRightY):
  lowerLeft_(Point_t(lowerLeftX, lowerLeftY)),
  upperRight_(Point_t(upperRightX, upperRightY))
{}

double likhachev::Rectangle::getArea() const
{
  return getWidth() * getHeight();
}

likhachev::Rectangle_t likhachev::Rectangle::getFrameRect() const
{
  double width = getWidth();
  double height = getHeight();
  Point_t pos((upperRight_.x + lowerLeft_.x) / 2, (upperRight_.y + lowerLeft_.y) / 2);

  return Rectangle_t(width, height, pos);
}

void likhachev::Rectangle::move(Point_t offset)
{
  upperRight_ += offset;
  lowerLeft_ += offset;
}

void likhachev::Rectangle::move(double offsetX, double offsetY)
{
   Point_t offset(offsetX, offsetY);
   move(offset);
}

void likhachev::Rectangle::scale(double multiplier)
{
  double width = getWidth();
  double height = getHeight();
  Point_t offset(((multiplier * width) - width) / 2, ((multiplier * height) - height) / 2);

  upperRight_ += offset;
  lowerLeft_ -= offset;
}

double likhachev::Rectangle::getWidth() const
{
  return upperRight_.x - lowerLeft_.x;
}

double likhachev::Rectangle::getHeight() const
{
  return upperRight_.y - lowerLeft_.y;
}
