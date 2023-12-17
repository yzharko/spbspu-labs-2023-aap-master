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
  return zheleznyakov::rectangle_t();
};

void move(double x, double y)
{

};

void move(zheleznyakov::point_t destinationPoint)
{

};

void scale(double k){

};