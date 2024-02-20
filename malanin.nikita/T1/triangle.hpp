#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
    Triangle(const malanin::point_t& vertex1, const malanin::point_t& vertex2, const malanin::point_t& vertex3);

    double getArea() const override;
    malanin::rectangle_t getFrameRect() const override
    {
        // Находим ограничивающий прямоугольник для треугольника
        double minX = std::min(std::min(vertex1_.x, vertex2_.x), vertex3_.x);
        double maxX = std::max(std::max(vertex1_.x, vertex2_.x), vertex3_.x);
        double minY = std::min(std::min(vertex1_.y, vertex2_.y), vertex3_.y);
        double maxY = std::max(std::max(vertex1_.y, vertex2_.y), vertex3_.y);

        double width = maxX - minX;
        double height = maxY - minY;
        malanin::point_t center = { minX + width / 2, minY + height / 2 };

        return {center, width, height };
    }

private:
    malanin::point_t vertex1_; // Координаты вершин треугольника
    malanin::point_t vertex2_;
    malanin::point_t vertex3_;
};

#endif