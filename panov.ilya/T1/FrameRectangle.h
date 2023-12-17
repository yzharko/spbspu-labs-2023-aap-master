#pragma once
#include "Point.h"
class FrameRectangle
{
private:
  double width_;
  double height_;
  Point pos_;

public:
  FrameRectangle();
  FrameRectangle(double width, double height, const Point& pos);
  ~FrameRectangle();

  void setWidth(double width);
  void setHeight(double height);
  void setPos(const Point& pos);

  double getWidth();
  double getHeight();
  Point getPos();
};