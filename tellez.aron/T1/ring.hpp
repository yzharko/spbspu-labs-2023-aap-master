#ifndef T1_RING_H
#define T1_RING_H
#include "shape.hpp"
#include "base-types.hpp"

namespace tellez
{
  class Ring : public Shape
  {
  public:
    Ring(point_t center, double outerRadius, double innerRadius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    Shape* clone() const override;

  private:
    point_t center_;
    double outerRadius_;
    double innerRadius_;
    void scaleWithoutVerify(double ds) override;
  };
}
#endif
