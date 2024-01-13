#ifndef FRAMERECTANGLE_H
#define FRAMERECTANGLE_H
#include "Point.h"

class FrameRectangle
{
private:
  double width_;
  double height_;
  Point pos_;
public:
  FrameRectangle();
  FrameRectangle(Point& pos, double width, double height);
  ~FrameRectangle();
  double getWidth();
  double getHeight();
  Point getLeftCorner();
  Point getRightCorner();
  Point getCenter();
  void show();
  void scale(double k);
  void move(double xdist, double ydist);
};
#endif
