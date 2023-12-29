#include "rectangle.hpp"

batunov::rectangle::rectangle(const rectangle_t& rect) :
    rect_(rect)
{}
double batunov::rectangle::getArea() const
{
    return rect_.width * rect_.height;
}
batunov::rectangle_t batunov::rectangle::getFrameRect() const
{
    return rect_;
}
void batunov::rectangle::move(const point_t& newPos)
{
    rect_.pos = newPos;
}
void batunov::rectangle::move(double dx, double dy)
{
    rect_.pos.x += dx;
    rect_.pos.y += dy;
}
void batunov::rectangle::scale(double coeff)
{
    rect_.width *= coeff;
    rect_.height *= coeff;
}
