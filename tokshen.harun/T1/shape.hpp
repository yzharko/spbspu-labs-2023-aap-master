#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
  public:
    virtual ~Shape() {};
	virtual double getArea() const = 0;
	virtual Rectangle_t getFrameRect() const = 0;
	virtual void move(const Point_t& offset) = 0;
	virtual void move(double offsetX, double offsetY) = 0;
	virtual void scale(double multiplier) = 0;
};
#endif
