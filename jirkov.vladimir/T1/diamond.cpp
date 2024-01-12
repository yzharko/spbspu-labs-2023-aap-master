#include "diamond.hpp"
#include <cmath>
using namespace jirkov;
Diamond::Diamond(point_t topPoint, point_t rightPoint, point_t centerPoint) :
    topPoint_(topPoint),
    rightPoint_(rightPoint),
    centerPoint_(centerPoint),
    firstSide_(std::abs(topPoint.y - centerPoint.y)),
    secondSide_(std::abs(rightPoint.y - centerPoint.y))
{}

double Diamond::getArea() const
{
    return (2 * firstSide_ * secondSide_);
}

rectangle_t jirkov::Diamond::getFrameRect() const
{
    point_t pos = centerPoint_;
    double height = firstSide_ * 2;
    double width = secondSide_ * 2;
    return rectangle_t{ width, height, pos };
}

void Diamond::move(const point_t & destination)
{
    double dx = centerPoint_.x - destination.x;
    double dy = centerPoint_.y - destination.y;
    centerPoint_ = destination;
    rightPoint_.x += dx;
    topPoint_.x += dx;
    rightPoint_.y += dy;
    topPoint_.y += dy;
}

void Diamond::move(double moveX, double moveY)
{
    centerPoint_.x += moveX;
    centerPoint_.y += moveY;
    rightPoint_.x += moveX;
    topPoint_.x += moveX;
    rightPoint_.y += moveY;
    topPoint_.y += moveY;
}

void Diamond::scale(double k)
{
    rightPoint_.x *= k;
    topPoint_.x *= k;
    rightPoint_.y *= k;
    topPoint_.y *= k;
    firstSide_ *= k;
    secondSide_ *= k;
}
