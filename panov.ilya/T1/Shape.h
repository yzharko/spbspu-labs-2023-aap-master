#pragma once
#include "FrameRectangle.h"
#include <string>

template <typename T>
void FigInfo(T figure);
class Shape
{
public:
  virtual double getArea() = 0;
  virtual FrameRectangle getFrameRectangle() = 0;
  virtual void move(double xdist, double ydist) = 0;
  virtual void scale(double k) = 0;
  virtual Shape* clone() = 0;
  virtual std::string getName() const = 0;
};