#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace sadofeva
{
  struct Point_t
  {
  public:
    double x;
    double y;
  };
  struct Rectangle_t
  {
  public:
    Point_t pos;
    double width;
    double height;
  };
}
#endif
