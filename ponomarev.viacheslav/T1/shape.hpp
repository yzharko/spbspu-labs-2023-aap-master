#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <stdexcept>
#include "base-types.hpp"

namespace ponomarev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & newCenter) = 0;
    virtual void move(const double & offsetX, const double & offsetY) = 0;
    void scale(const double k)
    {
      if (k <= 0)
      {
        throw std::invalid_argument("Wrong input scale coefficient");
      }
      else
      {
        scaling(k);
      }
    }

  private:
    virtual void scaling(const double k) = 0;
  };
}

#endif
