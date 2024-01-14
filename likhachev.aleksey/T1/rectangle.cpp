#include "rectangle.hpp"

likhachev::Rectangle::Rectangle(point_t lowerLeft, point_t upperRight):
  lowerLeft_(lowerLeft),
  upperRight_(upperRight)
{
  if (lowerLeft_.x >= upperRight_.x || lowerLeft_.y >= upperRight_.y) {
    throw std::logic_error("The parameters are not logically incorrect\n");
  }
}

likhachev::Rectangle::Rectangle(double lowerLeftX, double lowerLeftY, double upperRightX, double upperRightY)
{
  lowerLeft_.x = lowerLeftX;
  lowerLeft_.y = lowerLeftY;
  upperRight_.x = upperRightX;
  upperRight_.y = upperRightY;

  if (lowerLeft_.x >= upperRight_.x || lowerLeft_.y >= upperRight_.y) {
    throw std::logic_error("The parameters are not logically incorrect\n");
  }
}

double likhachev::Rectangle::getArea() const
{
  return getWidth() * getHeight();
}

likhachev::rectangle_t likhachev::Rectangle::getFrameRect() const
{
  double width = getWidth();
  double height = getHeight();
  likhachev::point_t pos = getPos();
  likhachev::rectangle_t result;
  result.width = width;
  result.height = height;
  result.pos = pos;

  return result;
}

void likhachev::Rectangle::move(const point_t& offset)
{
  likhachev::point_t pos = getPos();
  move(offset.x - pos.x, offset.y - pos.y);
}

void likhachev::Rectangle::move(double offsetX, double offsetY)
{
  likhachev::point_t offset;
  offset.x = offsetX;
  offset.y = offsetY;
  upperRight_ += offset;
  lowerLeft_ += offset;
}

void likhachev::Rectangle::scale(double multiplier)
{
  double width = getWidth();
  double height = getHeight();
  likhachev::point_t offset;
  offset.x = ((multiplier * width) - width) / 2;
  offset.y = ((multiplier * height) - height) / 2;

  upperRight_ += offset;
  lowerLeft_ -= offset;
}

likhachev::point_t likhachev::Rectangle::getPos() const
{
  likhachev::point_t pos;
  pos.x = (upperRight_.x + lowerLeft_.x) / 2;
  pos.y = (upperRight_.y + lowerLeft_.y) / 2;
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
