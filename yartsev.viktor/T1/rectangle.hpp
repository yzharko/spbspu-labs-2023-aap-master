#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <shape.hpp>
#include <base-types.hpp>

namespace yartsev {
  class Rectangle : public yartsev::Shape {
    public:
      virtual double getArea() const override;
      virtual yartsev::rectangle_t getFrameRect() override;
      virtual void move(const point_t & to) override;
      virtual void move(const double & dx, const double & dy) override;
      virtual void scale(const double & scaling) override;
    private:
      rectangle_t rectangle;
  };
}

#endif
