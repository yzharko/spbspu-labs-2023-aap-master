#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.h"

class Rectangle : public Shape {
public:
  explicit Rectangle();

  void setWidth(double);

  double getWidth() const;

  void setHeight(double);

  double getHeight() const;

  PointT getCPoint() const;

  long long getArea() override;

  RectangleT getFrameRect() override;

  void move(PointT) override;

  void move(double x, double y) override;

  void scale(double) override;

  friend std::istream &operator>>(std::istream &, Rectangle &);
private:
  double width;
  double height;
  PointT cPoint;
};

#endif
