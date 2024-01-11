#pragma once
#include "Shape.h"
#include "Point.h"

class Diamond : public Shape
{
private:
  Point center_;
  double diagHor_;
  double diagVert_;
public:
  Diamond();
  Diamond(Point& center, double diagHor, double diagVert);
  Diamond(const Diamond& Diamond);
  Diamond(Diamond&& Diamond) noexcept;
  Diamond(double x, double y, double diagHor, double diagVert);
  ~Diamond();
  Diamond& operator=(const Diamond& Diamond);
  Diamond& operator=(Diamond&& Diamond) noexcept;
  Point getCenter();
  double getdiagHor();
  double getdiagVert();
  virtual double getArea();
  virtual FrameRectangle getFrameRectangle();
  virtual void move(double xdist, double ydist);
  virtual void scale(double k);
  virtual Shape* clone();
  virtual std::string getName() const;
};
