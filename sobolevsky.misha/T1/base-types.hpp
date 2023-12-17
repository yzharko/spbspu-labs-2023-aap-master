#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace sobolevsky
{
  class Point_t
  {
  private:
    double x;
    double y;
  };

  class Rectangle_t
  {
  private:
    double width;
    double height;
    Point_t pos;
  };
}

#endif
