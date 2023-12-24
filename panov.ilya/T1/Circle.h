#pragma once
#include "Shape.h"
#include <string>

class Circle : public Shape
{
private:
  Point center_;
  double radius_;

public:
  Circle();
  Circle(const Point& center, double radius);
  ~Circle();

  Point getCenter();
  double getRadius();
  double getArea();
  FrameRectangle getFrameRectangle();
  void move(double dx, double dy);
  void scale(double size);
  Shape* clone();
  std::string getName();


};