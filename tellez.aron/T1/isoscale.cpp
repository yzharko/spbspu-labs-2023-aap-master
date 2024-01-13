#include "isoscale.hpp"
#include <stdexcept>
#include "base-types.hpp"

using namespace tellez;

void tellez::isoScaleWithVerify(Shape * shape, scale_t scale)
{
  if (scale.ds <= 0)
  {
    throw std::logic_error("bad scale size");
  }
  isoScaleWithoutVerify(shape, scale);
}

point_t diffPoint(const point_t & one, const point_t & two)
{
  return {one.x - two.x, one.y - two.y};
}

point_t resizePoint(const point_t & point, const scale_t & scale)
{
  return {diffPoint(point, scale.pos).x * scale.ds, diffPoint(point, scale.pos).y * scale.ds};
}

void tellez::isoScaleWithoutVerify(Shape * shape, scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  shape->scaleWithoutVerify(scale.ds);
  shape->move(resizePoint(pos, scale).x, resizePoint(pos, scale).y);
}
