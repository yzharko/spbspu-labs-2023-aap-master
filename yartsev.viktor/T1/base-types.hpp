#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace yartsev {
  struct point_t {
    point_t();
    point_t(double x, double y);
    double x_;
    double y_;
  };

  struct rectangle_t {
    double getArea();
    point_t getLowerPoint();
    point_t getTopPoint();
    rectangle_t();
    rectangle_t(double width, double height, point_t pos);
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
