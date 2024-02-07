#include "parallelogram.hpp"

likhachev::Parallelogram::Parallelogram(point_t pointB, point_t pointA, point_t pointD):
  pointA_(pointA),
  pointB_(pointB),
  pointD_(pointD)
{
  if (pointA_ == pointB_ || pointB_ == pointD_ || pointD_ == pointA_) {
    throw std::logic_error("The parameters are not logically incorrect\n");
  }

  if (!(pointA_.y == pointB_.y || pointA_.y == pointD_.y)){
    throw std::logic_error("The parameters are not logically incorrect\n");
  }

  if ((pointD_.x - pointA_.x) / (pointB_.x - pointA_.x) == (pointD_.y - pointA_.y) / (pointB_.y - pointA_.y)){
    throw std::logic_error("The parameters are not logically incorrect\n");
  }
}

double likhachev::Parallelogram::getArea() const
{
  return getWidth() * getHeight();
}

likhachev::rectangle_t likhachev::Parallelogram::getFrameRect() const
{
  double fullWidth = getWidth() + getSubWidth();
  double height = getHeight();
  likhachev::point_t pos;
  pos.x = (pointB_.x + pointD_.x) / 2;
  pos.y = (pointB_.y + pointD_.y) / 2;

  likhachev::rectangle_t result;
  result.width = fullWidth;
  result.height = height;
  result.pos = pos;

  return result;
}

void likhachev::Parallelogram::move(const point_t& offset)
{
  likhachev::point_t pos;
  pos.x = (pointB_.x + pointD_.x) / 2;
  pos.y = (pointB_.y + pointD_.y) / 2;
  move(offset.x - pos.x, offset.y - pos.y);
}

void likhachev::Parallelogram::move(double offsetX, double offsetY)
{
  likhachev::point_t offset;
  offset.x = offsetX;
  offset.y = offsetY;
  pointA_ += offset;
  pointB_ += offset;
  pointD_ += offset;
}

void likhachev::Parallelogram::scale(double multiplier)
{
  likhachev::point_t pos = getPos();
  if (multiplier < 1) {
    multiplier = (1 - multiplier) * -1;
  } else {
    multiplier -= 1;
  }

  int xMultiplier = 1;
  int yMultiplier = 1;
  if (pointA_.y == pointB_.y) {
    if (pointA_.x < pointB_.x) {
      xMultiplier = -1;
    }
    if (pointA_.y > pointD_.y) {
      yMultiplier = -1;
    }

  } else {
    if (pointA_.x < pointD_.x) {
      xMultiplier = -1;
    }
    if (pointA_.y > pointB_.y) {
      yMultiplier = -1;
    }
  }

  pointA_.x += (pos.x - pointA_.x) * multiplier * xMultiplier;
  pointB_.x += (pos.x - pointB_.x) * multiplier * xMultiplier;
  pointD_.x += (pos.x - pointD_.x) * multiplier * xMultiplier;

  pointA_.y += (pos.y - pointA_.y) * multiplier * yMultiplier;
  pointB_.y += (pos.y - pointB_.y) * multiplier * yMultiplier;
  pointD_.y += (pos.y - pointD_.y) * multiplier * yMultiplier;
}

double likhachev::Parallelogram::getWidth() const
{
  likhachev::point_t widthPoint;
  if (pointA_.y == pointB_.y) {
    widthPoint = pointB_;
  } else {
    widthPoint = pointD_;
  }

  double width = 0;
  if (pointA_.x > widthPoint.x) {
    width = pointA_.x - widthPoint.x;
  } else {
    width = widthPoint.x - pointA_.x;
  }

  return width;
}

likhachev::point_t likhachev::Parallelogram::getPos() const
{
  likhachev::point_t pos;
  pos.x = (pointB_.x + pointD_.x) / 2;
  pos.y = (pointB_.y + pointD_.y) / 2;
  return pos;
}

double likhachev::Parallelogram::getSubWidth() const
{
  likhachev::point_t subWidthPoint;
  if (pointA_.y == pointB_.y) {
    subWidthPoint = pointD_;
  } else {
    subWidthPoint = pointB_;
  }

  double subWidth = 0;
  if (pointA_.x > subWidthPoint.x) {
    subWidth = pointA_.x - subWidthPoint.x;
  } else {
    subWidth = subWidthPoint.x - pointA_.x;
  }

  return subWidth;
}

double likhachev::Parallelogram::getHeight() const
{
  double height = 0;
  if (pointB_.y > pointD_.y) {
    height = pointB_.y - pointD_.y;
  } else {
    height = pointD_.y - pointB_.y;
  }

  return height;
}
