#include "base-types.hpp"
#include "rectangle.hpp"

zheleznyakov::Rectangle::Rectangle(const point_t leftTopPoint, const point_t rightBottomPoint){
  double rectangleWidth = rightBottomPoint.x - leftTopPoint.x;
  double rectangleHeight = rightBottomPoint.y - leftTopPoint.y;
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

void zheleznyakov::Rectangle::scale(double k){

};