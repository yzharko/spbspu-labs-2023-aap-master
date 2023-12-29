#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-tapes.h"

namespace sadofeva
{
	class Shape 
	{
	public:
		virtual double getArea() const = 0;
		virtual void move(Point_t point) = 0;
		virtual Rectangle_t getFrameRect() const = 0;
		virtual void move(double _x, double _y) = 0;
		virtual void scale(double k) = 0;
	};
}
#endif
