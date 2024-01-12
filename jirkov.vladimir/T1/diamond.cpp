#include "diamond.hpp"
#include <cmath>
jirkov::Diamond::Diamond(point_t topPoint, point_t rightPoint, point_t centerPoint) :
    topPoint_(topPoint),
    rightPoint_(rightPoint),
    centerPoint_(centerPoint),
    firstSide_(std::abs(topPoint.y_ - centerPoint.y_)),
    secondSide_(std::abs(rightPoint.y_ - centerPoint.y_))
{}

double jirkov::Diamond::getArea()
{
    return (2 * firstSide_ * secondSide_);
}

jirkov::rectangle_t jirkov::Diamond::getFrameRect()
{
    jirkov::point_t pos = centerPoint_;
    double height = firstSide_ * 2;
    double width = secondSide_ * 2;
    return jirkov::rectangle_t{ width, height, pos };
}

void jirkov::Diamond::move(point_t destination)
{
    double dx = centerPoint_.x_ - destination.x_;
    double dy = centerPoint_.y_ - destination.y_;
    centerPoint_ = destination;
    rightPoint_.x_ += dx;
    topPoint_.x_ += dx;
    rightPoint_.y_ += dy;
    topPoint_.y_ += dy;
}

void jirkov::Diamond::move(double moveX, double moveY)
{
    centerPoint_.x_ += moveX;
    centerPoint_.y_ += moveY;
    rightPoint_.x_ += moveX;
    topPoint_.x_ += moveX;
    rightPoint_.y_ += moveY;
    topPoint_.y_ += moveY;
}

void jirkov::Diamond::scale(double k)
{
    rightPoint_.x_ *= k;
    topPoint_.x_ *= k;
    rightPoint_.y_ *= k;
    topPoint_.y_ *= k;
    firstSide_ *= k;
    secondSide_ *= k;
}
