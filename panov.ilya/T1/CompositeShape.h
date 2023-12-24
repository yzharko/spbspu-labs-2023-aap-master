#pragma once
#include "Shape.h"

class CompositeShape : public Shape
{
private:
  Point pos_;
  int maxs_;
  int currs_;
  Shape** shapes_;

public:

  CompositeShape();
  CompositeShape(int maxs);
  CompositeShape(const CompositeShape& comp);
  CompositeShape(CompositeShape&& comp) noexcept;
  ~CompositeShape();
  CompositeShape& operator=(const CompositeShape& comp);
  CompositeShape& operator=(CompositeShape&& comp) noexcept;
  void addShape(Shape* shape);
  Shape* operator[](int k);
  double getArea();
  FrameRectangle getFrameRectangle();
  void move(double dx, double dy);
  void scale(double size);
  Shape* clone();
  std::string getName();
};