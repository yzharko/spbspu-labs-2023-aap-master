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
    void moveTo(double x, double y) override;
    void moveBy(double x, double y) override;
    void scale(double factor) override;
  private:
    point_t points_[3];
    bool isValidRegular() const;
  };
}

#endif
