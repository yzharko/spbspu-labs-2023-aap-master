#pragma once
#include "FrameRectangle.h"
#include <string>

class Shape
{
public:
  virtual double getArea() = 0;
  virtual FrameRectangle getFrameRectangle() = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void scale(double size) = 0;
  virtual Shape* clone() = 0;
  virtual std::string getName() = 0;
  /*virtual CompositeShape& operator=(const CompositeShape& comp) = 0;
  virtual CompositeShape& operator=(CompositeShape&& comp) noexcept;*/
  virtual ~Shape() {}
};