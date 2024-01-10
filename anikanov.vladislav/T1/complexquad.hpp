#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <iosfwd>
#include "shape.h"

class Complexquad : public Shape {
public:
  explicit Complexquad();
  ~Complexquad() override = default;

  PointT getCPoint() const;

  long long getArea() override;

  RectangleT getFrameRect() override;

  void move(PointT) override;

  void move(double x, double y) override;

  void scale(double) override;

  friend std::istream &operator>>(std::istream &, Complexquad &);

private:
  PointT leftBottom, leftTop, rightTop, rightBottom, cPoint;

  double getDX(PointT fp, PointT sp);

  double getDY(PointT fp, PointT sp);

  double getDistance(PointT fp, PointT sp);

  double getTriangleArea(PointT fp, PointT sp, PointT tp);
};

#endif
