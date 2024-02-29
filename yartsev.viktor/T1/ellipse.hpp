#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace yartsev {
  class Ellipse : public yartsev::Shape {
    public:
      Ellipse();
      Ellipse(point_t & center, double radiusX, double radiusY);
      virtual double getArea() const override;
      virtual rectangle_t getFrameRect() override;
      virtual void move(const point_t & to) override;
      virtual void move(const double & dx, const double & dy) override;
      virtual void scale(const double & scaling) override;
    private:
      point_t center_;
      double radiusX_;
      double radiusY_;
  };
}

#endif
