#ifndef BASE_STRUCT_HPP
#define BASE_STRUCT_HPP

namespace malanin
{
  struct point_t
  {
    double x = 0.0;
    double y = 0.0;
  };

  struct rectrangle_t
  {
    double width = 0.0;
    double height = 0.0;
    point_t pos{0.0, 0.0};
  };
}


#endif
