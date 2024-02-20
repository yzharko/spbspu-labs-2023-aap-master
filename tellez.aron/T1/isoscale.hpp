#ifndef T1_ISOSCALE_H
#define T1_ISOSCALE_H
#include "base-types.hpp"
#include "shape.hpp"
namespace tellez
{
  void isoScaleWithVerify(Shape * shape, scale_t scale);
  void isoScaleWithoutVerify(Shape * shape, scale_t scale);
}
#endif
