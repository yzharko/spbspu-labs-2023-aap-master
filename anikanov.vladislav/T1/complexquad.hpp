#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <iosfwd>
#include "shape.hpp"

class Complexquad : public Shape {
public:
  explicit Complexquad();
  ~Complexquad() override = default;

  PointT getCPoint() const;

  long long getArea() override;

  RectangleT getFrameRect() override;

  void move(PointT) override;

  void move(float x, float y) override;

  void scale(float) override;

  friend std::istream &operator>>(std::istream &, Complexquad &);

private:
  PointT leftBottom, leftTop, rightTop, rightBottom, cPoint;

  float getDX(PointT fp, PointT sp);

  float getDY(PointT fp, PointT sp);

  float getDistance(PointT fp, PointT sp);

  float getTriangleArea(PointT fp, PointT sp, PointT tp);
};

#endif
