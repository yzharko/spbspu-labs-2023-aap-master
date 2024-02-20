#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"

namespace toksen
{
  class Parallelogram : public Shape
  {
    public:
      Parallelogram(const Point_t& center, const Point_t& p1, const Point_t& p2);
      virtual ~Parallelogram();

      double getArea() const override;
      Rectangle_t getFrameRect() const override;
      void move(const Point_t& offset) override;
      void move(double offsetX, double offsetY) override;
      void scale(double multiplier) override;

    private:
      Point_t center_;
      Point_t* points_;
  };
}
#endif
