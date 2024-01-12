#ifndef T1_RING_H
#define T1_RING_H
#include "shape.h"
#include "base-types.h"

class Ring : public Shape
{
public:
  Ring(point_t center, double outerRadius, double innerRadius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;
  //virtual void scale(double factor) = 0;
  Shape* clone() const override;

private:
  point_t center_;
  double outerRadius_;
  double innerRadius_;
  void scaleWithoutVerify(double ds) override;
};
#endif
