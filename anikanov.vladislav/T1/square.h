#ifndef SQUARE_H
#define SQUARE_H

#include <iosfwd>
#include "shape.h"

class Square : Shape {
private:
  double side;
  PointT cPoint;
public:
  explicit Square();

  void setSide(double);

  double getSide() const;

  PointT getCPoint() const;

  long long getArea() override;

  RectangleT getFrameRect() override;

  void move(PointT) override;

  void move(double x, double y) override;

  void scale(double) override;

  friend std::istream &operator>>(std::istream &, Square &);
};

#endif
