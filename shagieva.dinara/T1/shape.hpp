#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <stdexcept>
#include "base-types.hpp"

namespace shagieva
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const double & dx, const double & dy) = 0;
    virtual void move(const point_t & newCenter) = 0;
    void scale(const double scaleFactor)
    {
      if (scaleFactor <= 0)
      {
        throw std::invalid_argument("Invalid scale factor entered");
      }
      else
      {
        doScale(scaleFactor);
      }
    }

  private:
    virtual void doScale(const double scaleFactor) = 0;
  };
}

#endif
