#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"
#include <memory>

class CompositeShape : public Shape
{
public:
    CompositeShape();
    CompositeShape(const CompositeShape& other);
    CompositeShape* clone() const override;
    CompositeShape(CompositeShape&& other) noexcept;
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    ~CompositeShape() override;

    void addShape(Shape* shape);
    void removeShape(size_t index);
    size_t getShapesCount() const;
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(float dx, float dy) override;
    void scale(float scaleFactor) override;

private:
    std::unique_ptr<Shape* []> shapeptrs_;
    size_t shapes_;
    size_t capacity_;

    void expandCapacity();
};

#endif
