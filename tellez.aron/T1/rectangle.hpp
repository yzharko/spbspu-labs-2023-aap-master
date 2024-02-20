#ifndef T1_RECTANGLE_H
#define T1_RECTANGLE_H
#include "base-types.hpp"
#include "shape.hpp"

namespace tellez
{
  class Rectangle: public Shape
  {
    public:
      Rectangle(point_t one, point_t two);
      explicit Rectangle(rectangle_t rectangle);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double dx, double dy) override;
      void move(point_t position) override;
      void scale(double ds) override;
      Shape * clone() const override;
    protected:
      rectangle_t rect_;
  };
}
#endif
