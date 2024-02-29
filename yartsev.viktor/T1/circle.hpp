#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace yartsev {
  class Circle : public yartsev::Shape {
    public:
      Circle();
      Circle(point_t & center, double radius);
      virtual double getArea() const override;
      virtual rectangle_t getFrameRect() override;
      virtual void move(const point_t & to) override;
      virtual void move(const double & dx, const double & dy) override;
      virtual void scale(const double & scaling) override;
    private:
      point_t center_;
      double radius_;
  };
}

#endif
