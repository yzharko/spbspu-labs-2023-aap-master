#ifndef REGULAR_HPP
#define REGULAR_HH
#include <iostream>
#include "shape.hpp"

namespace toksen
{
  class Regular : public Shape
  {
    public:

      Regular(const Point_t& p1, const Point_t& p2, const Point_t& p3);
      virtual ~Regular();
      double getArea() const override;
      Rectangle_t getFrameRect() const override;
      void move(const Point_t& offset) override;
      void move(double offsetX, double offsetY) override;
      void scale(double multiplier) override;

    private:
      Point_t* points_;
  };
}
#endif
