#include "length.hpp"

double zheleznyakov::length(point_t a, point_t b)
{
  return std::sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}
