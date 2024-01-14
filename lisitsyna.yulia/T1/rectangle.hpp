#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace lisitsyna
{
  class Rectangle : public Shape
  {
    public:
      Rectangle(point_t one, point_t two);
      double getArea() const override;
      explicit Rectangle(rectangle_t rectangle);
      rectangle_t getFrameRect() const override;
      void move(double x, double y) override;
      void move(point_t point) override;
      void scale(double k) override;
    private:
      rectangle_t rectangle;
  };
}
#endif
