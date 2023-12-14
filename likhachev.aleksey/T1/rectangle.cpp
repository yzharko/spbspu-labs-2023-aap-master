#include "rectangle.hpp"

likhachev::Rectangle::Rectangle():
  lowerLeft_(Point_t()),
  upperRight_(Point_t())
{}

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
  double width = upperRight_.x - lowerLeft_.x; // (1) Lavran TODO: заменить на метод 
  double height = upperRight_.y - lowerLeft_.y;
  
  return width * height;
}

likhachev::Rectangle_t likhachev::Rectangle::getFrameRect() const
{
  double width = upperRight_.x - lowerLeft_.x; // Lavran TODO: заменить при появлении метода из (1)
  double height = upperRight_.y - lowerLeft_.y;
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
  double width = upperRight_.x - lowerLeft_.x; // Lavran TODO: заменить при появлении метода из (1)
  double height = upperRight_.y - lowerLeft_.y;
  Point_t offset(((multiplier * width) - width) / 2, ((multiplier * height) - height) / 2);

  upperRight_ += offset;
  lowerLeft_ -= offset;
}
