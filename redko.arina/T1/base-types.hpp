#ifndef BASETYPES_HPP
#define BASETYPES_HPP

namespace redko
{
  struct point_t
  {
    double x_;
    double y_;
  };

  struct rectangle_t
  {
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
