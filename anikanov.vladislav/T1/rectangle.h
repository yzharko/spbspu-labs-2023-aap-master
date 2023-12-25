#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <iosfwd>

class Rectangle : Shape {
private:
  double width;
  double height;
  PointT cPoint;
public:
  explicit Rectangle();

  void setWidth(double);

  double getWidth() const;

  void setHeight(double);

  double getHeight() const;

  void setCPoint(PointT);

  PointT getCPoint() const;

  long long getArea();

  RectangleT getFrameRect();

  void move(PointT);

  void move(double x, double y);

  void scale(double);

  friend std::istream &operator>>(std::istream &, Rectangle &);
};

#endif
