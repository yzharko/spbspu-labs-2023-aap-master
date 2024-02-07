#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
private:
  Point center_;
  double rad_;
public:
  Circle();
  Circle(Point& center, double rad_);
  Circle(const Circle& circle);
  Circle(Circle&& ring) noexcept;
  Circle(double x, double y, double rad_);
  ~Circle();
  Circle& operator=(const Circle& circle);
  Circle& operator=(Circle&& circle) noexcept;
  Point getCenter();
  double getRad();
  virtual double getArea();
  virtual FrameRectangle getFrameRectangle();
  virtual void move(double xdist, double ydist);
  virtual void scale(double k);
  virtual Shape* clone();
  virtual std::string getName() const;
  void show();
};
#endif
