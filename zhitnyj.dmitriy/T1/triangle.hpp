#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
    Triangle(const point_t& a, const point_t& b, const point_t& c);
    Triangle* clone() const override;
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(float dx, float dy) override;
    void scale(float scaleFactor) override;

private:
    point_t a_;
    point_t b_;
    point_t c_;
};

#endif
