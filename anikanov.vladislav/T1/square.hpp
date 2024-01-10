#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iosfwd>
#include "shape.hpp"

class Square : public Shape {
public:
  explicit Square();
  ~Square() override = default;

  void setSide(float);

  float getSide() const;

  PointT getCPoint() const;

  long long getArea() override;

  RectangleT getFrameRect() override;

  void move(PointT) override;

  void move(float x, float y) override;

  void scale(float) override;

  friend std::istream &operator>>(std::istream &, Square &);
private:
  float side;
  PointT cPoint;
};

#endif
