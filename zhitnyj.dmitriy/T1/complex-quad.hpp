#ifndef COMPLEX_QUAD_HPP
#define COMPLEX_QUAD_HPP

#include "shape.hpp"
#include "triangle.hpp"

class ComplexQuad : public Shape
{
public:
    ComplexQuad(const point_t& point1, const point_t& point2, const point_t& point3, const point_t& point4);
    ComplexQuad* clone() const override;
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(float dx, float dy) override;
    void scale(float scaleFactor) override;

private:
    point_t points_[4];
};

#endif
