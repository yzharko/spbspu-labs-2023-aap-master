#include "triangle.hpp"
#include <cmath>
#include <iostream>

using namespace malanin;

Triangle::Triangle(const point_t& vertex1, const point_t& vertex2, const point_t& vertex3)
    : vertex1_(vertex1), vertex2_(vertex2), vertex3_(vertex3)
{
}

double Triangle::getArea() const
{
    // Вычисляем площадь треугольника 
    double a = std::sqrt(std::pow(vertex2_.x - vertex1_.x, 2) + std::pow(vertex2_.y - vertex1_.y, 2));
    double b = std::sqrt(std::pow(vertex3_.x - vertex2_.x, 2) + std::pow(vertex3_.y - vertex2_.y, 2));
    double c = std::sqrt(std::pow(vertex1_.x - vertex3_.x, 2) + std::pow(vertex1_.y - vertex3_.y, 2));

    double p = (a + b + c) / 2;
    double area = std::sqrt(p * (p - a) * (p - b) * (p - c));

    return area;
}

