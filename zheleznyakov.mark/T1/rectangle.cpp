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
  rectangle_t newRectangle;
  newRectangle.pos.x = rectangle.pos.x + x;
  newRectangle.pos.y = rectangle.pos.y + y;
  rectangle = newRectangle;
};

void zheleznyakov::Rectangle::move(zheleznyakov::point_t destinationPoint)
{
  rectangle_t newRectangle;
  newRectangle.width = rectangle.width;
  newRectangle.height = rectangle.height;
  newRectangle.pos.x = destinationPoint.x;
  newRectangle.pos.y = destinationPoint.y;
  rectangle = newRectangle;
};

void zheleznyakov::Rectangle::scale(double k)
{
  rectangle_t newRectangle;
  newRectangle.width = rectangle.width * k;
  newRectangle.height = rectangle.height * k;
  newRectangle.pos.x = rectangle.pos.x * k;
  newRectangle.pos.y = rectangle.pos.y * k;
  rectangle = newRectangle;
};
