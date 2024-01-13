#include "base-types.hpp"
#include "rectangle.hpp"

zheleznyakov::Rectangle::Rectangle(const point_t leftBottomPoint, const point_t rightTopPoint)
{
  double rectangleWidth = rightTopPoint.x - leftBottomPoint.x;
  double rectangleHeight = rightTopPoint.y - leftBottomPoint.y;
  zheleznyakov::point_t currentRectangleCenter;
  currentRectangleCenter.x = (rectangleWidth) / 2;
  currentRectangleCenter.y = (rectangleHeight) / 2;
  rectangle.pos = currentRectangleCenter;
  rectangle.width = rectangleWidth;
  rectangle.height = rectangleHeight;
};

double zheleznyakov::Rectangle::getArea()
{
  return rectangle.height * rectangle.width;
};

zheleznyakov::rectangle_t zheleznyakov::Rectangle::getFrameRect()
{
  return rectangle;
};

void zheleznyakov::Rectangle::move(double x, double y)
{
  rectangle.pos.x += x;
  rectangle.pos.y += y;
};

void zheleznyakov::Rectangle::move(zheleznyakov::point_t destinationPoint)
{
  rectangle.pos.x = destinationPoint.x;
  rectangle.pos.y = destinationPoint.y;
};

void zheleznyakov::Rectangle::scale(double k)
{
  rectangle.width *= k;
  rectangle.height *= k;
  rectangle.pos.x *= k;
  rectangle.pos.y *= k;
};

bool zheleznyakov::checkIsRectangleCoords(double x1, double y1, double x2, double y2)
{
  return x1 < x2 && y1 < y2;
};
