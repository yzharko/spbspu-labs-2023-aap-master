#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace smolyakov
{
  class Regular : public Shape
  {
  public:
    Regular(point_t center, point_t secondPoint, point_t thirdPoint);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void moveTo(point_t shift) override;
    void moveBy(point_t shift) override;
    void scale(double factor) override;
  private:
    point_t center_;
    double innerRadius_;
    double outerRadius_;
    int sides_;
    void calculateParameters(point_t, point_t, point_t);
  };
}

#endif
