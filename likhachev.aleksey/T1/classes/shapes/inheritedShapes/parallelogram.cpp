#include "parallelogram.hpp"

likhachev::Parallelogram::Parallelogram(Point_t pointA, Point_t pointB, Point_t pointD):
  pointA_(pointA),
  pointB_(pointB),
  pointD_(pointD)
{}

likhachev::Parallelogram::Parallelogram(double pointAX, double pointAY, double pointBX, double pointBY, double pointDX, double pointDY):
  pointA_(Point_t(pointAX, pointAY)),
  pointB_(Point_t(pointBX, pointBY)),
  pointD_(Point_t(pointDX, pointDY))
{}

double likhachev::Parallelogram::getArea() const
{
  return getWidth() * getHeight();
}

likhachev::Rectangle_t likhachev::Parallelogram::getFrameRect() const
{
  double fullWidth = getWidth() + getSubWidth();
  double height = getHeight();
  Point_t pos((pointB_.x + pointD_.x) / 2, (pointB_.y + pointD_.y) / 2);

  return Rectangle_t(fullWidth, height, pos);
}

void likhachev::Parallelogram::move(Point_t offset)
{
  Point_t pos((pointB_.x + pointD_.x) / 2, (pointB_.y + pointD_.y) / 2);
  move(offset.x - pos.x, offset.y - pos.y);
}

void likhachev::Parallelogram::move(double offsetX, double offsetY)
{
  Point_t offset(offsetX, offsetY);
  pointA_ += offset;
  pointB_ += offset;
  pointD_ += offset;
}

void likhachev::Parallelogram::scale(double multiplier)
{
  double width = getWidth();
  double height = getHeight();
  Point_t offset(((multiplier * width) - width) / 2, ((multiplier * height) - height) / 2);

  if (pointA_.y == pointB_.y) {
    int xMultiplier = 1;
    int yMultiplier = 1;
    if (pointA_.x < pointB_.x) {
      xMultiplier = -1;
    }
    if (pointA_.y < pointD_.y) {
      yMultiplier = -1;
    }

    pointA_.x += offset.x * xMultiplier;
    pointD_.x += offset.x * xMultiplier;
    pointB_.x -= offset.x * xMultiplier;

    pointA_.y += offset.y * yMultiplier;
    pointB_.y += offset.y * yMultiplier;
    pointD_.y -= offset.y * yMultiplier;

  } else {
    int xMultiplier = 1;
    int yMultiplier = 1;
    if (pointA_.x < pointD_.x) {
      xMultiplier = -1;
    }
    if (pointA_.y < pointB_.y) {
      yMultiplier = -1;
    }

    pointA_.x += offset.x * xMultiplier;
    pointB_.x += offset.x * xMultiplier;
    pointD_.x -= offset.x * xMultiplier;

    pointA_.y += offset.y * yMultiplier;
    pointD_.y += offset.y * yMultiplier;
    pointB_.y -= offset.y * yMultiplier;
  }
}

double likhachev::Parallelogram::getWidth() const
{
  Point_t widthPoint(0, 0);
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

double likhachev::Parallelogram::getSubWidth() const
{
  Point_t subWidthPoint(0, 0);
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
